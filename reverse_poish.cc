#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

class Stack{
public: 
void push(double);
double pop(void);
  Stack();
  ~Stack();

private: 
  double val[MAXVAL];
  int top;
};

Stack::Stack()
{
  top = 0;
  val[0] = 0;
}

Stack::~Stack()
{
}

void Stack::push(double f)
{
  
  int tmp;

  if ((this->top) < MAXVAL)
  {
    tmp = this->top++;
    printf("top is %d. \n", tmp);
    this->val[tmp] = f;
    printf("%g is pushed. \n\n", f);
  }
  else
    printf("error: stack full, can't push %g\n", f);
}

double Stack::pop(void)
{
  int tmp;
  if ((this->top) > 0) {
    tmp =  this->top;
//printf("top is %d. \n", tmp); 
    cout << "top is " << tmp << ".\n";
    tmp = --this->top;
//printf("%g is popped. \n\n", val[tmp]);    
    cout << val[tmp]  << " is popped. \n\n";
    return val[tmp];
  }
  else {
//printf("error: stack empty\n");
    cout << "error: stack empty\n";
    return 0.0;
  }
}

/* prototype declarations */
int getop(char []);

/* a main function */
main()
{
  Stack s1;
  int type;
  double op2;
  char s[MAXOP];
  
  /* a debug 
  s1.push(1);
  s1.push(3);
  s1.push(5);
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();
  */
 
  while((type = getop(s)) != EOF) {
      switch(type) {
      case NUMBER:
        s1.push(atof(s));
  break;
      case '+':
	s1.push(s1.pop() + s1.pop());
	break;
      case '*':
        s1.push(s1.pop() * s1.pop());
	break;
      case '-':
	op2 = s1.pop();
        s1.push(s1.pop() - op2);
	break;
      case '/':
	op2 = s1.pop();
	if (op2 != 0.0)
	  s1.push(s1.pop() / op2);
	else
//printf("error: zero deviser\n");
          cout << "error: zero deviser\n";
	break;
	//      case '%':
	///	op2 = pop();
	//	if (op2 != 0.0)
	//	  push(double(int(pop()) % int(op2)));
	//	else
	//	  printf("error: zero deviser\n");
	//	break;
      case '\n':
//printf("\t%.8g\n", s1.pop());
        cout << "\t" << s1.pop() << "\n";
	break;
      default:
	printf("error: unknown command %s \n", s);
	break;
      }
    }
    

  return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if  (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else 
    buf[bufp++] = c;
}
