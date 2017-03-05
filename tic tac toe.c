#include <stdio.h>

int v=0,i,j,m=0,n=0,g,h,k;
char a[3][3],ch,t;

char checkwin(char f, int p, int q);

int printboard()
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            t=a[i][j];
            printf("  ");
            if(t!='P')
                printf("%c",a[i][j]);
            else
                printf(" ");
            printf("  ");
            if(j!=2)
            printf("|");
        }
        printf("\n");
    }
    if(v==0)
    {
    	return inputm();
    }
    else if(v==2)
    {
    	printf("Computer Won and You Lost\n");
    	return 2;
    }
    return 0;
}

int inputm()
{
	int d;
	inp:
	printf("What is your next move? (1-9)\n");
	scanf("%d",&d);
	printf("\n\n");
	i=(d-1)/3;
	j=(d-1)%3;
	t=a[i][j];
	if(t!='P')
	{
		printf("You can't move in that square as it is already marked\n");
		goto inp;
	}
	else
	{
		a[i][j]='X';
		if(m<3)
		m++;
		if(m>=2)
		{
			ch=checkwin('Y',0,0);
			if(ch=='X')
			{
				v=1;
				printf("You Won and Computer Lost\n");
				return 1;
			}
		}
	}
	return 0;
}

char checkwin(char f, int p, int q)
{
	char b[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	if(f!='Y')
	{
		b[p][q]=f;
	}

	for(i=0;i<3;i++)
	{
		if(b[i][0]!='P' && b[i][1]!='P' && b[i][2]!='P')
		{
			if(b[i][0]==b[i][1] && b[i][1]==b[i][2])
			return b[i][0];
		}
	}

	for(i=0;i<3;i++)
	{
		if(b[0][i]!='P' && b[1][i]!='P' && b[2][i]!='P')
		{
			if(b[0][i]==b[1][i] && b[1][i]==b[2][i])
			return b[0][i];
		}
	}

	if(b[0][0]!='P' && b[1][1]!='P' && b[2][2]!='P')
	{
		if(b[0][0]==b[1][1] && b[1][1]==b[2][2])
		return b[0][0];
	}

	if(b[0][2]!='P' && b[1][1]!='P' && b[2][0]!='P')
	{
		if(b[0][2]==b[1][1] && b[1][1]==b[2][0])
		return b[0][2];
	}

	return 'Z';
}

int win()
{
	if(n>=2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(a[i][j]=='P')
				{
					ch=checkwin('O',i,j);
					if(ch=='Z')
						continue;
					else
					{
						v=2;
						a[i][j]='O';
						return printboard();
					}

				}
			}
		}
		return 0;
	}
	else
	return 0;
}

int lose()
{
	if(m>=2)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(a[i][j]=='P')
				{
					ch=checkwin('X',i,j);
					if(ch=='Z')
						continue;
					else
					{
						a[i][j]='O';
						if(n<3)
						n++;
						return printboard();
					}

				}
			}
		}
		return 0;
	}
	else
	return 0;
}

int spaces()
{
/*	if(n==0)
	{
		a[1][1]='O';
		n++;
	}*/
	if(a[0][0]=='P')
	{
		a[0][0]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[0][2]=='P')
	{
		a[0][2]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[2][0]=='P')
	{
		a[2][0]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[2][2]=='P')
	{
		a[2][2]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[1][1]=='P')
	{
		a[1][1]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[0][1]=='P')
	{
		a[0][1]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[1][0]=='P')
	{
		a[1][0]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[1][2]=='P')
	{
		a[1][2]='O';
		if(n<3)
		n++;
		return printboard();
	}
	if(a[2][1]=='P')
	{
		a[2][1]='O';
		if(n<3)
		n++;
		return printboard();
	}
	return 3;
}

int main(void) {
	for(i=0;i<3;i++)
	{
    		for(j=0;j<3;j++)
    		a[i][j]='P';
	}
	while(1)
	{
		g=win();
		if(g==2)
		break;

		h=lose();
		if(h==2)
		continue;
		if(h==1)
		break;

		k=spaces();
		if(k==0)
		continue;
		if(k==1)
		break;

		printf("Game Draw\n");
		break;
	}
	return 0;
}
