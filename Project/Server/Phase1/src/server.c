/**
 * @file server.h
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Entry Point for the Server
 * 
 */

#include <stdio.h>		    // for standard system I/O stuff
#include <errno.h>		    // for error handling on system call
#include <sys/types.h>		// for system defined types
//#include <sys/ipc.h>		// for IPC permission structure
//#include <sys/shm.h>		// for shared memory facility defines
#include <string.h>

#include "students.h"
#include "student.h"
#include "studentData.h"

#define size 4096 //block memory size
#define shmkey 0x7700 + 01 //key for shmget()
#define IPC_RESULT_ERROR (-1) //error returning -1 if sharded id could not be created
#define DELIMITER " "
int main() {

    // Initialize the Logger

    // Initialize Student Data
    struct students studentData;
    if (student_file_exists)
        studentData = student_file_load();
    else {
        studentData = student_data_init();
    }

    // Create the Shared Memory space for student data
    int shared_memory_id;
    shared_memory_id = shmget(shmkey, size, IPC_CREAT | 0666);
    if(shared_memory_id == IPC_RESULT_ERROR){
        printf("Error: shmget() failed, errno = %i\n", errno);
        perror("shmget()");
    }
    else
        printf("shmget() successful, shared_memory_id = %i\n", shared_memory_id);
    
    // Loop to poll activity and update data

    
    
        char active_users[27][20];
        char* token;
        token = strtok(result, DELIMITER);
        int counter=0;
    
    FILE *fpipe;
    char *command = "who";
    char result[1024]={0x0};

    if (0 == (fpipe = (FILE*)popen(command, "r")))
    {
        perror("popen() failed.");
        exit(EXIT_FAILURE);
    }

    while (fgets(result, sizeof(result), fpipe) !=NULL)
       {
           strcpy(token, active_users[counter]);
            counter++
        }

                  
    pclose(fpipe);
    

   
    // Cleanup
    student_file_save(studentData);

    // Exit Successfully
    return 0;
}
