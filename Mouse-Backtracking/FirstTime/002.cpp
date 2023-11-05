#include<iostream>
using namespace std;

class stack
{
	public:
		stack()
		{
			x=0;
			y=0;
			under=NULL;
		}
		int x;
		int y;
		stack * under;
};

void push(stack*& fir,int row,int col)
{
	stack* ptr=new stack;
	ptr->x=row;
	ptr->y=col;
	if(fir==NULL)
	{
	        fir=ptr;
	}
	else
	{
		ptr->under=fir;
		fir=ptr;
	}
}
void pull(stack*& fir)
{
	stack *cur;
	cur=fir;
	fir=fir->under;
	delete cur;
}
int path(int (*map)[12])
{
	stack* mouse=NULL;
	int row=1,col=1;
	map[row][col]=2;
	while(map[8][10]!=2)
	{
		if(map[row-1][col]==0)
		{
			push(mouse,--row,col);
			cout<<"運行到map["<<row<<"]["<<col<<"]"<<endl;
			map[row][col]=2;
		}
		else if(map[row+1][col]==0)
		{
			push(mouse,++row,col);
			cout<<"運行到map["<<row<<"]["<<col<<"]"<<endl;
			map[row][col]=2;
		}
		else if(map[row][col-1]==0)
		{
			push(mouse,row,--col);
			cout<<"運行到map["<<row<<"]["<<col<<"]"<<endl;
			map[row][col]=2;
		}
		else if(map[row][col+1]==0)
		{
			push(mouse,row,++col);
			cout<<"運行到map["<<row<<"]["<<col<<"]"<<endl;
			map[row][col]=2;
		}
		else
		{
			pull(mouse);
			row=mouse->x;
			col=mouse->y;
			cout<<"回到map["<<row<<"]["<<col<<"]"<<endl;
		}
	}
        cout<<"找到出口！"<<endl;
	return 0;
}

int main()
{
	int map[10][12]={
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,1,1,1,1,1,1},
		{1,1,1,0,1,1,0,0,0,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,0,0,0,0,1,1,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1},
		{1,1,0,0,0,0,0,0,1,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<12;j++)
		{
	                cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	path(map);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}

}
