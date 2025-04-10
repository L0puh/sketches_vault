#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define PORT "/dev/ttyUSB1"
#define COMMAND "amixer sget Master | grep 'Right:' | awk -F'[][]' '{gsub(\"%\", \"\", $2); print $2 }'"
#define RATE B9600
#define SLEEP 1

std::string get_volume(){
  char buffer[128];
  FILE *fp = popen(COMMAND, "r");
  if (fp == NULL) {
    perror("popen failure");
    return 0;
  }

  fgets(buffer, sizeof(buffer), fp);
  pclose(fp);
  return buffer;
}

void write_serial(int fd, std::string data){
   write(fd, data.c_str(), data.length()); 
   write(fd, "\n", 1);
   printf("current volume: %s", data.c_str());
}

void init_fd(int fd){
   struct termios opts;
   tcgetattr(fd, &opts);
   opts.c_cflag = RATE | CS8 | CREAD | CLOCAL;
   opts.c_iflag = IGNPAR;
   opts.c_oflag = 0;
   opts.c_lflag = 0;
   tcflush(fd, TCIFLUSH);
   tcsetattr(fd, TCSANOW, &opts);
}

int main(){
   int fd = open(PORT, O_WRONLY | O_NOCTTY);
   if (fd == -1) {
      perror("fd open failure (no connection with the port...)");
      return -1;
   }
   init_fd(fd);

   while(true){
      std::string volume = get_volume();
      write_serial(fd, volume);
      sleep(SLEEP);
   }
   return 0;
}
