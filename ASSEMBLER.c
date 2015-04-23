#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define number 129
int countlabel=0;

//the differents functions
int pass1();
void pass2();
void help();
void displaysymboltable();
void menu();
void displaycode();
void displaymachinecode();

struct opcodes
{
    char code[10];
    int len;
};

//storing opcodes in a structure

//NOTE: 1 MEANS IT IS 1 ADRESSABLE, O MEANS IT IS REGISTER , 2 MEANS 2 ADRESSABLE , 3 MEANS 3 ADRESSABLE AND 4 MEANS 0 ADRESSABLES
struct opcodes s[number]=
{	
	{"R0",-1},
	{"R1",-1},
	{"R2",-1},
	{"R3",-1},
	{"R4",-1},
	{"R5",-1},
	{"R6",-1},
	{"R7",-1},
	{"R8",-1},
	{"R9",-1},
	{"R10",-1},
	{"R11",-1},
	{"R12",-1},
	{"R13",-1},
	{"R14",-1},
	{"R15",-1},
	{"F0",-2},
	{"F1",-2},
	{"F2",-2},
	{"F3",-2},
	{"F4",-2},
	{"F5",-2},
	{"F6",-2},
	{"F7",-2},
	{"F8",-2},
	{"F9",-2},
	{"F10",-2},
	{"F11",-2},
	{"F12",-2},
	{"F13",-2},
	{"F14",-2},
	{"F15",-2},
	{"START",4},
	{"MIN",3},
	{"F_MIN",3},
	{"MAX",3},
	{"F_MAX",3},
	{"POWER",3},
	{"F_POWER",3},
	{"ADD",2},
	{"F_ADD",2},
	{"SUM",2},
	{"F_SUM",2},
	{"MUL",2},
	{"F_MUL",2},
	{"DIV",2},
	{"F_DIV",2},
	{"SHIFTLI",2},
	{"SHIFTRI",2},
	{"ROLLLCD",2},
	{"ROLLRCD",2},
	{"MOV",2},
	{"LOAD",2},
	{"F_LOAD",2},
	{"STORE",2},
	{"F_STORE",2},
	{"FACT",2},
	{"COMPARE",2},
	{"F_COMPARE",2},
	{"AND",2},
	{"OR",2},
	{"XOR",2},
	{"NOR",2},
	{"NAND",2},
	{"SUMC",2},
	{"F_SUMC",2},
	{"SUBB",2},
	{"F_SUBB",2},
	{"SUB",2},
	{"F_SUB",2},
	{"F_MOV",2},
	{"DEC",1},
	{"INC",1},
	{"F_DEC",1},
	{"F_INC",1},
	{"SHIFTL",1},
	{"SHIFTR",1},
	{"PUSH",1},
	{"POP",1},
	{"IN",1},
	{"OUT",1},
	{"ROLLLC",1},
	{"ROLLRC",1},
	{"STEP",1},
	{"STEPC",1},
	{"STEPNC",1},
	{"STEPP",1},
	{"STEPM",1},
	{"STEPZ",1},
	{"STEPNZ",1},
	{"STEPPE",1},
	{"STEPPO",1},
	{"STEPL",1},
	{"STEPG",1},
	{"STEPE",1},
	{"GO",1},
	{"GOC",1},
	{"GONC",1},
	{"GOP",1},
	{"GOM",1},
	{"GOZ",1},
	{"GONZ",1},
	{"GOPE",1},
	{"GOPO",1},
	{"GOL",1},
	{"GOG",1},
	{"GOE",1},
	{"ROLLR",1},
	{"ROLLL",1},
	{"CLC",1},
	{"NOT",1},
	{"CLEAR",4},
	{"SETC",4},
	{"RET",4},
	{"RETC",4},
	{"RETNC",4},
	{"RETP",4},
	{"RETM",4},
	{"RETZ",4},
	{"RETNZ",4},
	{"RETPE",4},
	{"RETPO",4},
	{"RETL",4},
	{"RETG",4},
	{"RETE",4},
	{"NOP",4},
	{"HLT",4},
	{"DI",4},
	{"EI",4}
};

// main function 
int main()
{
	menu(); // this function displays the menu.
	return 0;
}

//function to display the menu
void menu()
{
	int choice,ret;

	printf("\n\n\tAssembler to Our ISA::\n");
	printf("\tThe menu is:\n");
	printf("\t1.Display Assembly Language Code.\n"); // displays the code you have typed.
	printf("\t2.Display Machine Code.\n");  // displays the machine code generated on the console itself.
	printf("\t3.Display Symbol Table.\n"); // displays only the symbol table and no machine code is generated.
	printf("\t4.Generate Machine Code.\n"); // generates all the files symbol table file and machine code file but not displayed on console.
	printf("\t5.ISA Help.\n"); // to display the isa help
	printf("\t6.Exit.\n"); // to exit from file
	printf("\n\nEnter your choice?\n");
	scanf("%d",&choice);
	switch(choice)
	{
		
		case 1:

				printf("\n\tThe Assembly Language Code is:\n");
				displaycode();
				menu();
				break;
		
		case 2:
				ret=pass1();
				if(ret!=0)
				{
					printf("\n%d Errors in code.Please check the program.!\n",ret);
					menu();
				}
				else
				{
					pass2(); // pass2 function generates the machine code.
					displaymachinecode();
					menu();
				}
				break;
		case 3:
			
				ret=pass1();
				if(ret!=0)
				{
					printf("Cannot Display Symbol Table.\n");
					printf("\n%d Errors in code.Please check the program.!\n",ret);
					menu();
				}
				else
				{
					printf("The symbol Table is as follows::\n\n");
					displaysymboltable(); //displays the symbol table
					menu();
				}
				break;

		case 4:

				ret=pass1();
				if(ret!=0)
				{
					printf("\n%d Errors in code.Please check the program.!\n",ret);
					menu();
				}
				else
				{
					pass2(); // pass2 function generates the machine code.
					menu();
				}
				break;

		case 5:
				
				printf("The help is as follows::\n\n");
				help(); // displays the isa help.
				menu();
				break;

		case 6:

				exit(0);
				break;
		
		default:

				printf("Wrong Choice.Enter again..!!");
				menu();
	
	}
}

//function to display ISA help
void help()
{
	//function to display ISA help.
	int c;
	FILE *file;
	file=fopen("HELP", "r");
	if(file) 
	{
	    while( (c = getc(file))!= EOF )
	    {    
	    	putchar(c);
	    }
    	fclose(file);
	}
}

//displays the assembly code on console
void displaycode()
{
	// displays the code you have typed
	int c;
	FILE *file;
	file=fopen("CODE","r");
	if(file) 
	{
	    while( (c = getc(file))!= EOF )
	    {    
	    	putchar(c);
	    }
    	fclose(file);
	}
}

//displays the symbol table on the console
void displaysymboltable()
{
	//function to display Symbol Table.
	int c;
	FILE *file;
	file=fopen("SYMBOLTABLE", "r");
	if(file) 
	{
	    while( (c = getc(file))!= EOF )
	    {    
	    	putchar(c);
	    }
    	fclose(file);
	}	
}


// displays the machine code on console
void displaymachinecode()
{
	int c;
	FILE *file;
	file=fopen("MACHINECODE", "r");
	if(file) 
	{
	    while( (c = getc(file))!= EOF )
	    {    
	    	putchar(c);
	    }
    	fclose(file);
	}	
}


int pass1()
{
	FILE *f1,*f2;
	f1 = fopen("CODE","r"); //file containing assembly language codes using new ISA opened in read mode
	f2 = fopen("SYMBOLTABLE","w"); //pass one file opened in write mode ,"symbol table file"
	char str[20];
	int i,ilc=1,flag=0,ret=0; //ilc keeps track of line number
	char opcd[20];
	int len;
	char c;
	int flag2=0;
	int wordcount=0,temp;
	int floatr=0,intr=0;
	fprintf(f2,"SYMBOL TABLE\n");		
	fprintf(f2,"LABEL NAME\tILC\n");
	while( fscanf(f1,"%s",str)==1 )
	{
            //printf("wordcount: %d word: %s\n",wordcount,str);
			floatr=0;
			intr=0;
            flag2=0;
            for(i=0;i<number;i++) // loop to check if it is opcode or label
			{
                strcpy(opcd,s[i].code);
				flag=0;
				len=strlen(opcd);
				if( (strcmp(str,opcd))==0 )
				{	 
                   	if(str[0]=='F' && str[1]=='_')
                   	{
                   		floatr=1;
                   	}
                   	if(s[i].len==-1)
                   	{
                   		intr=1;
                   	}
                   	wordcount++;
                   	flag=1;
                   	if(s[i].len==4)
                   	{
                   		temp=1;
                   	}
                   	if(s[i].len==1)
                   	{
                   		temp=2;
                   	}
                   	if(s[i].len==2)
                   	{
                   		temp=3;
                   	}
                   	if(s[i].len==3)
                   	{
                   		temp=4;
                   	}
					break;
				}
			}
			len=strlen(str);
			// to check illegal use of registers.
			if(intr==floatr && intr==1)
			{
				printf("\nWrong combination of OPCODE and Registers.\n\nF_* instructions are for flaoting point calculations and others for integer calculations.\nFor Further Help Check Help.\n");
				ret++;
			}
			if( (str[len-1]==':' && str[0]!='_') )
			{
				wordcount++;
				flag=1;
				fprintf(f2,"%s",str);
				fprintf(f2,"\t%d\n",ilc);
			}
			if( (str[len-1]==':' && str[0]=='_') )
			{			
				wordcount++;
				flag2=1;
			}
	        if( c=fgetc(f1)=='\n' )
            {
            	if(wordcount!=temp)
	        	{
	        		printf("Count: %d temp: %d\n",wordcount,temp);
	        		printf("Wrong Syntax of OPCODE. Please refer to Help.\n");
	        		ret++;
	        	}
            	wordcount=0;
            	ilc++;
            }
	        if(!flag && flag2==0)
	        {
				//in neither label nor opcode then it is invalid opcode which is not in our ISA 
				printf ("Error at line %d\n",ilc);
				ret++;
            }
	}
	fclose(f1);
	fclose(f2);
	return ret;
}

void pass2()
{
	//printf("This is pass2\n");
	FILE *f1,*f2,*f3,*f4;
	f2 = fopen("SYMBOLTABLE","r"); //pass1 file opened in read mode ,"symbol table file"
	f3 = fopen("MACHINECODE","w"); //machine code file
	f4 = fopen("CODE","r");
	char str[20],str1[20];
	int i,ilc=1,ret=0; //ilc keeps track of line number
	char opcd[20],bin[20];
	int len=0;
	char c;
	while( fscanf(f4,"%s",str1)==1 )
	{
            //printf("Code Read: %s\n",str1);
            f1=fopen("ISACODES.txt","r"); //file containing assembly language codes using new ISA opened in read mode
            while( fscanf(f1,"%s",str)==1 )
            {
             	fscanf(f1,"%s",bin);
             	//printf("str:%s bin:%s \n",str,bin);   
				if( (strcmp(str1,str))==0 )
				{	 
                   	//printf("opcode\n");
                   	fprintf(f3,"%s",bin); // writing the binary value of the opcode in machine code file.
					break;
				}
			}
			len=strlen(str1);
			if( (str1[len-1]==':') && str1[0]=='_')
			{
				//printf("label\n");
				fprintf(f3,"\n"); // leaving a plain line if label encountered.
			}
			if( (str1[len-1]==':') && str1[0]!='_' )
			{
				// conversion of ilc to binary and writing it in file.
				char garbage[30],label[20];
				int h;
				f2 = fopen("SYMBOLTABLE","r"); //pass1 file opened in read mode ,"symbol table file"
				fscanf(f2,"%s",garbage); //scanning the info
				fscanf(f2,"%s",garbage);
				fscanf(f2,"%s",garbage);
				fscanf(f2,"%s",garbage);
				fscanf(f2,"%s",garbage);
				while( fscanf(f2,"%s",label)==1 )
				{		
					fscanf(f2,"%d",&h);
					switch(h)
					{
				
						case 0: 
								fprintf(f3,"0000\n");
								break;

						case 1: 
								fprintf(f3,"0001\n");
								break;

						case 2: 
								fprintf(f3,"0010\n");
								break;

						case 3: 
								fprintf(f3,"0011\n");
								break;

						case 4: 
								fprintf(f3,"0100\n");
								break;
						case 5: 
								fprintf(f3,"0101\n");
								break;

						case 6: 
								fprintf(f3,"0110\n");
								break;

						case 7: 
								fprintf(f3,"0111\n");
								break;

						case 8: 
								fprintf(f3,"1000\n");
								break;

						case 9: 
								fprintf(f3,"1001\n");
								break;

						case 10: 
								fprintf(f3,"1010\n");
								break;

						case 11:
								fprintf(f3,"1011\n");
								break;

						case 12:
								fprintf(f3,"1100\n");
								break;

						case 13:
								fprintf(f3,"1101\n");
								break;

						case 14:
								fprintf(f3,"1110\n");
								break;

						case 15:
								fprintf(f3,"1111\n");
								break;
					}
				}
				fclose(f2);
			}

            if( c=fgetc(f1)=='\n' )
            {
            	ilc++;
            	fprintf(f3,"\n"); // new line for next line of code.
            }
            fclose(f1);
		
	}
	fclose(f3);
	fclose(f4);
}