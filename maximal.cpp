#include<iostream>

using namespace std;
int n,m;	// No. of points in 3d , in input and in output

struct point	//representation of a point
{
	int x,y,z,index,max;	//max is a flag to check maximality
}*p;

void max_find()
{
	int i,j,equity;	//equity is for those cases having more than 1 point with same x co-ordinate
	for(i=0;i<n;i++)
	{
		if(p[i].max==0) continue;
		equity=i;
		for(j=i+1;j<n;j++)
		{
			if (p[j].x==p[i].x)
			{
				if ((p[equity].y <= p[j].y) && (p[equity].z <= p[j].z)) equity=j;
			}
			else break;
		}
		for(j=i;j<equity;j++) p[j].max=0;
		if(i<equity) continue;
		for(j=i+1;j<n;j++)
		{
			if (p[j].max==0) continue;
			if ((p[j].y < p[i].y) && (p[j].z < p[i].z)) p[j].max=0;
		}
	}
}

void take_input()	//take 3D points as input
{
	int i;
	cin>>n;  
	p=new point[n];
	for (i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y>>p[i].z;
		p[i].index=i;
		p[i].max=1;
	}	
}

void get_output()
{
	int i;
	m=0;
	for(i=0;i<n;i++)
	{
		if(p[i].max==1)
		{
			p[m]=p[i];
			m++;
		}
	}
}
int random(int x,int y,int z)
{
	int ret;
	ret=((x%2)*2 + (y%2))*2 +(z%2);
	return ret;
}

void sort(point *arr,int size)	// sort the points along x-axis using quick sort
{
	point temp;
	int rnd,i,j;
	if (size <= 1) {return;}
	if (size > 20)	// slight randomization in pivot element
	{
		rnd=random(arr->x,arr->y,arr->z);
		rnd= (size/4) + rnd;
		temp=arr[0];
		arr[0]=arr[rnd];
		arr[rnd]=temp;
	}
	i=0;
	j=1;
	while(j<size)	//partition
	{
		if((arr[j].x)>(arr[0].x))
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		j++;
	}
	temp=arr[i];
	arr[i]=arr[0];
	arr[0]=temp;
	sort(arr,i);
	sort(arr+i+1,size-i-1);
}


int main()
{
	int i;
	take_input();
	sort(p,n);
	max_find();
	get_output();
	cout<<m<<endl;
	for (i=m-1;i>=0;i--)
	{
		cout<<p[i].index<<endl;
	}
	delete[] p;
	return 0;
}
