#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void about_devs(void);//list of developers

int hour, minute,second;//manual variables
int hours, minutes, seconds;//alam variables


void display_time(void);
void display_clock_options(void);
void key_board_detect(void);


//updating the clock manually
void Time_update(void);
void manual_update(void);
void get_hours_manual(void);
void get_minutes_manual(void);
void get_seconds_manual(void);
void display_manual_time(void);


//setting the alam
void setting_alam_comfirm(void);//comfirm user choice
void alam(void);//interface for setting alam
void get_hours(void);
void get_minutes(void);
void get_seconds(void);


int main()
{
	system("color 3F");
    display_time();

    return 0;
}

void display_time(void){

    while(1){
  
  
            system("cls");
        time_t duration;
        duration=time(NULL);

        struct tm *current;
        current=localtime(&duration);

        char buffer[10];
        display_clock_options();

        strftime(buffer,10,"%H:%M:%S",current);

        printf("\n\tCurrent Time: %s",buffer);
        if(current->tm_hour >= 12 && current->tm_hour < 24){
    	printf(" PM\n");
	}
	else printf(" AM\n");
        sleep(1);
    
        				//ALARM RING
				    if(hours ==  current->tm_hour && minutes == current->tm_min &&  seconds == current->tm_sec){
					system("cls");
				    
				    int i;
				    for(i = 1; i < 300; i++){
				    	printf("\n\t\tTHE ALARM IS RINGING...\n");
				    	printf("___________________________________________________________________________________________\n\n");
				        
				        printf("\tPress any key to Dismiss\n");
				        
				        Beep(950000000, 90);
				        system("cls");//clear previous message
				        
				        //detect alam dismiss
				        if( _kbhit() ){
				        	break;
						}//end if that detect alam dismiss
				    }
					//end for
					}//end if alam
        
        
        if (_kbhit()) { // Check if a key is pressed
            char key = _getch();
            if (key == '1') { 
            Time_update();
             //
			    break;
            } else if (key == '2') {
            
              setting_alam_comfirm();
          }
            
			
             else if (key == '3') { // Quit the program
                		YES_NO_AUTO:	
                				
				    	system("cls");
				    	char yn;
				    	printf("\nARE YOU SURE YOU WANT TO EXIT CLOCK?\n\n");
				    	
				    	printf("Press Y for YES/ N for NO: ");
				    	yn = getche();
				         
				        switch(yn){
				        	case 'y':
				        	case 'Y':
				        		exit(1);//user exit the clock
				        		break;
				        	
				        	case 'n':
				        	case 'N':
				        		display_time();//bring user back to clock after regretting exit
				        		break;
				        		
				        	default:
				        		system("cls");
				        	goto YES_NO_AUTO;//choose valid option on exit
				        	
				        	
						}//end of inner switch for  yes or no
            }//end else for exit or not
        }//end keyboard hit

    }//end while loop
}//end fun display time

void display_clock_options(void){
    printf("\t*******DIGITAL CLOCK SYSTEM*******\n");
    printf("___________________________________________________________________________________________\n\n");
    printf(" Clock Options\n\n");
    printf(" 1. Reset Time\n");
    printf(" 2. Set Alarm\n");
    printf(" 3. Exit Clock\n");
    
  //  about_devs();
}



	void Time_update(void){
	char choice;
	CHOOSE_AGAIN:
	system("cls");
	printf("CHOOSE ONE OF THE OPTION BELOW\n\n");
	printf("___________________________________________________________________________________________\n");
		
		
	printf("\n Press 1 for manual update\n");
	printf(" Press 2 for automatic update\n");
	printf(" Press 0 to go back to clock\n");
	
	printf("\n Enter choice: ");
	


	choice = getche();
	system("cls");
	
	switch(choice){
	case '1':
	   manual_update();
	    break;
	case '2':
	case '0':
		display_time();//send user back to home screen if 0 or 2 pressed
	    break;
	default:
		/*sleep(1);
		system("cls");
	        printf("Please enter key 1 or 2\n");
	        
	       // system("cls");
	       */
	   goto CHOOSE_AGAIN;
	   }
	   
}//end function time update

/*
manual:
if(choice==1){

  printf(" enter hour (0-23) :");
  scanf("%d",&hour);
  system("cls");
  printf(" enter minute (0-59) :");
  scanf("%d",&minute);
  system("cls");
  printf(" enter second (0-59) :");
  scanf("%d",&second);



automatic:
if(choice==2)
{

    display_time();
}


}// end void function

*/

void manual_update(void){
	system("cls");
	printf("\t*****MANUAL TIME UPDATE*******\n");
	printf("___________________________________________________________________________________________\n");
	
	printf(" Enter hour (0-23) :");
	get_hours_manual();
	
	printf(" Enter minutes(0-59): ");
	get_minutes_manual();
	
	printf(" Enter seconds(0-59): ");
	get_seconds_manual();
	
	display_manual_time();
	
}

//get hrs manual
void get_hours_manual(void){
	int hr_status;//store status that there was wrong input(character)
	system("cls");//cleans everything back
	printf("*****MANUAL TIME UPDATE*******\n");
	printf("___________________________________________________________________________________________\n");
	
	printf("Enter hours: ");
    HR://for correct input 
    HR_2://for correct input 
    hr_status = scanf("%d", &hour);//also detect if user entered a character
    getchar();
    if(hour < 0|| hour >23){
    	printf("\nINVALID INPUT\n");
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("*****MANUAL TIME UPDATE*******\n");
		printf("___________________________________________________________________________________________\n");
		printf("Please enter HOURS in a range of 0 to 23: ");
		goto HR;	
	}
	else if (hr_status == 0){//detect if user entered a character
		printf("\nINVALID INPUT\n");
		//feedback to user
		Sleep(1300);//wait for user to see the feadback
		
		system("cls");
		printf("*****MANUAL TIME UPDATE*******\n");
		printf("___________________________________________________________________________________________\n");
		printf("Please enter HOURS in numbers in a range of 0 to 23: ");
		goto HR_2;//detect input character
	}
}//end get_hr_manual

void get_minutes_manual(void){
	int min_status;//store status that there was wrong input(character)
	
	system("cls");//cleans everything back
	printf("*****MANUAL TIME UPDATE*******\n");//header
	printf("___________________________________________________________________________________________\n");
	
	printf("\nEnter minutes: ");
    MINS://for correct input 
    MIN_2://for correct input
    min_status = scanf("%d", &minute);//also detect if a character is entered
    getchar();//collect roaming character
    if(minute < 0 || minute > 59){
    	printf("\n\nINVALID INPUT\n");//feedback to user
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("*****MANUAL TIME UPDATE*******\n");//redisplays the header
		printf("___________________________________________________________________________________________\n");
		printf("\nPlease enter MINUTES in a range of 0 to 59: ");//prompt user for correct input
		goto MINS;	
	}
	else if (min_status == 0){//detect if user entered a character
		printf("\n\nINVALID INPUT\n");//feedback to user
		
		Sleep(1300);//wait for user to see the feadback
		
		system("cls"); 
		printf("*****MANUAL TIME UPDATE*******\n"); //redisplays the header
		printf("___________________________________________________________________________________________\n");
		printf("\nPlease enter MINUTES in numbers in a range of 0 to 59: ");//prompt user for correct input
		goto MIN_2;//detect input character
	}
}// end get mins manual


void get_seconds_manual(void){
	int sec_status;//store status that there was wrong input(character)
	
	system("cls");//cleans everything back
	printf("*****MANUAL TIME UPDATE*******\n");
	printf("___________________________________________________________________________________________\n");
	
	printf("\nEnter seconds: ");
    SEC://for correct input 
    SEC_2://for correct input 
    sec_status = scanf("%d", &second);//also detect if a character is entered
    getchar();//collect wrong character
    
    if(second < 0 || second > 59){
    	printf("\n\nINVALID INPUT\n");//feedback to user
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("*****MANUAL TIME UPDATE*******\n");//redisplays the header
		printf("___________________________________________________________________________________________\n");
		printf("\nPlease enter SECONDS in a range of 0 to 59: ");//prompt user for correct input
		goto SEC;//send user back for input again
	}
	else if (sec_status == 0){//detect if user entered a character
		printf("\n\nINVALID INPUT\n");//feedback to user
		
		Sleep(1300);//wait for user to see the feadback
		
		system("cls"); 
		printf("*****MANUAL TIME UPDATE*******\n"); //redisplays the header
		printf("___________________________________________________________________________________________\n");
		printf("\nPlease enter SECONDS in numbers in a range of 0 to 59: ");//prompt user for correct input
		
		goto SEC_2;//detect input character
	}
}//end get_seconds_manual function



void display_manual_time(void){
	while(1){
	
	//ALARM RING
				    if(hours ==  hour && minutes == minute &&  seconds == second){
					system("cls");
				    
				    int i;
				    for(i = 1; i < 300; i++){
				    	printf("\n\t\tTHE ALARM IS RINGING...\n");
				    	printf("___________________________________________________________________________________________\n\n");
				        
				        printf("\tPress any key to Dismiss\n");
				        
				        Beep(950000000, 90);
				        system("cls");//clear previous message
				        
				        //detect alam dismiss
				        if( _kbhit() ){
				        	break;
						}//end if that detect alam dismiss
				    }
				    minute += 2;
					//end for
					}//end if alarm ring
	
	display_clock_options();
	
    printf("\t\t\tTIME: %02d:%02d:%02d", hour,minute,second);
    if(hour >= 12 && hour < 24){
    	printf(" PM\n");
	}
	else printf(" AM\n");
    
    second++;
  // printf("\n\n");
   /*puts(" press 'a' to reset the time again ");
   puts(" press 'b' to use the stop watch or timer ");
   puts(" press 'c' to use the alarm ");
   puts(" press 'd' to exit the clock");
    */
	if(kbhit()){

        char ch=getch();
        switch(ch){

    case '1':
		system("cls");
      Time_update();
        break;

    case '2':
        system("cls");
        setting_alam_comfirm();
        
         break;


    case '3':
    					YES_NO:
    					
    					
				    	system("cls");
				    	char yn;
				    	printf("\nARE YOU SURE YOU WANT TO EXIT CLOCK?\n\n");
				    	
				    	printf("Press Y for YES/ N for NO: ");
				    	yn = getche();
				         
				        switch(yn){
				        	case 'y':
				        	case 'Y':
				        		exit(1);
				        		break;
				        	
				        	case 'n':
				        	case 'N':
				        		display_manual_time();
				        		break;
				        		
				        	default:
				        		system("cls");
				        		goto YES_NO;
				        	
						}//end of inner switch for  yes or no
						
         // for exiting the console screen
       break;
     /*  
    default:
         system("cls");
        printf("\n you entered invalid key press any key to return to clock  ");
         getch();
         int z =kbhit();// when any key is pressed it redirects to the reseted time
         if(z==1)
         {
              break;
         }
		*/



        }// end switch



    }// end if


    if(second==60)
    {
        second=0;
        minute++;

        if(minute==60){

            minute=0;
            hour++;
            if(hour==24){
                hour=0;
                minute=0;
                second=0;

            }

        }

    }// end main if
    sleep(1);// delay the time after one second
system("cls");


}// end while
}// end if option of manual reset
	
	
	
void alam(void){
	int alam_hours, alam_minutes, alam_seconds;
	
	int alam_counter;
	system("cls");
	
	printf("******SET YOUR ALARM*****\n");
	printf("___________________________________________________________________________________________\n\n");
	printf("Enter hours: ");
	get_hours();
	
	printf("Enter minutes: ");
	get_minutes();
	
	printf("Enter seconds: ");
	get_seconds();
	
	
	printf("\n\nAlarm set  successfully\n");
	sleep(2);
	
	
//	return alam_hours, alam_minutes, alam_seconds;
	//go back to current alam while clock was  set to current time
	
	
}//end alam


//setting the alam
void setting_alam_comfirm(void)
{
	char choice;
	
	CHOOSE_AGAIN: //if user didnot press 1 or 2
	system("cls");
	printf("SETTING ALARM\n");
	printf("___________________________________________________________________________________________\n\n");
	printf("1. Set alarm\n");
	printf("2. Cancel setting alarm\n");
	
	choice = getch();
	switch(choice){
		case '1':
			alam();		
			break;
		case '2':
			//auto back to clock
			break;
		default:
			printf("\nWrong input!\nPress 1 or 2\n");
			Sleep(1500);
			goto CHOOSE_AGAIN;
		
	}//end switch
	
}//end setting_alam_option

void get_hours(void){
	int hr_status;//store status that there was wrong input(character)
	system("cls");//cleans everything back
	printf("******SETTING ALARM*******\n");
	printf("___________________________________________________________________________________________\n");
	
	printf("Enter hours: ");
    HR://for correct input 
    HR_2://for correct input 
    hr_status = scanf("%d", &hours);//also detect if user entered a character
    getchar();
    if(hours < 0|| hours >23){
    	printf("\nINVALID INPUT\n");
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("******SETTING ALARM*****\n");
		printf("__________________________________\n");
		printf("Please enter HOURS in a range of 0 to 23: ");
		goto HR;	
	}
	else if (hr_status == 0){//detect if user entered a character
		printf("\nINVALID INPUT\n");
		//feedback to user
		Sleep(1300);//wait for user to see the feadback
		
		system("cls");
		printf("SETTING ALAM\n");
		printf("__________________________________\n");
		printf("Please enter HOURS in numbers in a range of 0 to 23: ");
		goto HR_2;//detect input character
	}
}//end get_hr

//get minutes from the user
void get_minutes(void){
	int min_status;//store status that there was wrong input(character)
	
	system("cls");//cleans everything back
	printf("SETTING ALARM\n");
	printf("__________________________________\n");
	
	printf("\nEnter minutes: ");
    MINS://for correct input 
    MIN_2://for correct input 
    min_status = scanf("%d", &minutes);//also detect if a character is entered
    getchar();//collect roaming character
    if(minutes < 0|| minutes > 60){
    	printf("\n\nINVALID INPUT\n");
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("SETTING ALARM\n");//redisplays the header
		printf("__________________________________\n");
		printf("\nPlease enter HOURS in a range of 0 to 23: ");//prompt user for correct input
		goto MINS;	
	}
	else if (min_status == 0){//detect if user entered a character
		printf("\n\nINVALID INPUT\n");
		//feedback to user
		Sleep(1300);//wait for user to see the feadback
		
		system("cls"); 
		printf("SETTING ALARM\n"); //redisplays the header
		printf("__________________________________\n");
		printf("\nPlease enter MINUTES in numbers in a range of 0 to 23: ");//prompt user for correct input
		goto MIN_2;//detect input character
	}
}//end get_munnutes function

//get seconds from the user
void get_seconds(void){
	int sec_status;//store status that there was wrong input(character)
	
	system("cls");//cleans everything back
	printf("SETTING ALARM\n");
	printf("__________________________________\n");
	
	printf("\nEnter seconds: ");
    SEC://for correct input 
    SEC_2://for correct input 
    sec_status = scanf("%d", &seconds);//also detect if a character is entered
    getchar();//collect wrong character
    
    if(seconds < 0 || seconds > 59){
    	printf("\n\nINVALID INPUT\n");//feedback to user
    	Sleep(1300);//wait for user to see the feadback
    	
    	system("cls");
		printf("SETTING ALAM\n");//redisplays the header
		printf("__________________________________\n");
		printf("\nPlease enter SECONDS in a range of 0 to 59: ");//prompt user for correct input
		goto SEC;//send user back for input again
	}
	else if (sec_status == 0){//detect if user entered a character
		printf("\n\nINVALID INPUT\n");//feedback to user
		
		Sleep(1300);//wait for user to see the feadback
		
		system("cls"); 
		printf("SETTING ALAM\n"); //redisplays the header
		printf("\nPlease enter SECONDS in numbers in a range of 0 to 59: ");//prompt user for correct input
		
		goto SEC_2;//detect input character
	}
}//end get_seconds function



void about_devs(void){
	printf("\n   BACHELOR OF SCIENCE IN INFORMATION AND COMMUNICATION TECHNOLOGY\n");
	printf("___________________________________________________________________________________________\n\n");
	
	Printf("Press 0 to go back to clock");
	
	
}










/*

void timer_stop_watch(void){
	CHOOSE_AGAIN:
	
	system("cls");
	puts(" \n\t\t\t  WELCOME TO THE TIMER-STOPWATCH\n");
      
	  printf("_____________________________________________________________________________________________\n\n");
	  
      printf("\t\t\t  CHOOSE YOUR OPTION BELOW \n\n");
      
      printf("  \t\t\t Press 1 for Stop-Watch\n");
      printf("  \t\t\t Press 0 to go back Clock\n");
      
      

    char stop_timer_choice;
    
	stop_timer_choice = getche();
	
	

	switch(stop_timer_choice){
		case '1':
			start();

			system("cls");
		//	start();
				break;
	
		case '0':
			//back to clock
			break;
		default:
			goto CHOOSE_AGAIN;
}

}//end timer_stop_watch function










/*

	int start(){
	      int num;
	     // int TTT;
	     system("cls"); //clears the console
	     
	    printf("\n\t\t\t    WELCOME TO THE STOPWATCH\n"
		"__________________________________________________________________________________________\n\n");
         printf("\n___________________________________________________________________________________________\n \r\t\t\t\t[HRS] "
        " [MIN]  [SEC]\n\t\t\t\t  %02d    %02d     %02d ",h,m,s); // hours ,minutes ,second

      
      
      
      
      
	 }//end of start function

*/
