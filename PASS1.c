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
	{"R0",0},
	{"R1",0},
	{"R2",0},
	{"R3",0},
	{"R4",0},
	{"R5",0},
	{"R6",0},
	{"R7",0},
	{"R8",0},
	{"R9",0},
	{"R10",0},
	{"R11",0},
	{"R12",0},
	{"R13",0},
	{"R14",0},
	{"R15",0},
	{"F0",0},
	{"F1",0},
	{"F2",0},
	{"F3",0},
	{"F4",0},
	{"F5",0},
	{"F6",0},
	{"F7",0},
	{"F8",0},
	{"F9",0},
	{"F10",0},
	{"F11",0},
	{"F12",0},
	{"F13",0},
	{"F14",0},
	{"F15",0},
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


int main()
{
	menu(); // this function displays the menu.
	return 0;
}

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
	
	fprintf(f2,"SYMBOL TABLE\n");		
	fprintf(f2,"LABEL NAME\tILC\n");
	while( fscanf(f1,"%s",str)==1 )
	{
            flag2=0;
            for(i=0;i<number;i++) // loop to check if it is opcode or label
			{
                strcpy(opcd,s[i].code);
				flag=0;
				len=strlen(opcd);
				if( (strcmp(str,opcd))==0 )
				{	 
                   	flag=1;
					break;
				}
			}
			len=strlen(str);
			if( (str[len-1]==':' && str[0]!='_') )
			{
				flag=1;
				fprintf(f2,"%s",str);
				fprintf(f2,"\t%d\n",ilc);
			}
			if( (str[len-1]==':' && str[0]=='_') )
			{			
				flag2=1;
			}
	        if(!flag && flag2==0)
	        {
				//in neither label nor opcode then it is invalid opcode which is not in our ISA 
				printf ("Error at line %d\n",ilc);
				ret++;
            }
            if( c=fgetc(f1)=='\n' )
            {
            	ilc++;
            }
		
	}
	fclose(f1);
	fclose(f2);
	return ret;
}

void pass2()
{
	printf("This is pass2\n");
	FILE *f1,*f2,*f3,*f4;
	f2 = fopen("SYMBOLTABLE","r"); //pass1 file opened in read mode ,"symbol table file"
	f3 = fopen("MACHINECODE","w"); //machine code file
	f4 = fopen("CODE","r");
	char str[20],str1[20];
	int i,ilc=1,ret=0; //ilc keeps track of line number
	char opcd[20],bin[20];
	int len=0;
	char c;
	//fpos_t pos;
	while( fscanf(f4,"%s",str1)==1 )
	{
            printf("Code Read: %s\n",str1);
            f1=fopen("ISACODES.txt","r"); //file containing assembly language codes using new ISA opened in read mode
            while( fscanf(f1,"%s",str)==1 )
            {
             	fscanf(f1,"%s",bin);
             	//printf("str:%s bin:%s \n",str,bin);   
				if( (strcmp(str1,str))==0 )
				{	 
                   	//printf("opcode\n");
                   	 
                   	fprintf(f3,"%s ",bin); // writing the binary value of the opcode in machine code file.
					//fgetpos(f3, &pos);
					//fsetpos(f3, &pos-1);
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