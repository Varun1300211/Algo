#include<iostream>
using namespace std;
   void merge(int **a, int startrow ,int startcol ,int m,int n,int midrow ,int midcol)
	{
        int n1=midcol-startcol+1;
		 int n2=n-midcol;
			int Lr[midrow-startrow+1];
	     	int Rr[m-midrow];
	     	int Lc[midcol-startcol+1];
	     	int Rc[n-midcol];
	     	for(int i=0;i<=m-startrow;i++)
	     {
	     	for(int j=0;j<midcol-startcol+1;j++)
	     	{
	     	    Lc[j]=a[i+startrow][startcol+j];
			 }
			for (int j=0;j<n-midcol;j++)
			{
       			Rc[j] = a[i+startrow][midcol+1+j];
       		}
			 int j=0;
			 int k=0;
			 int l=startcol;
			 while (j<n1 && k<n2) {

			        if (Lc[j]<=Rc[k])
					{
			            a[i+startrow][l]=Lc[j];
			            j++;
			        }
			        else
					{
			            a[i+startrow][l]=Rc[k];
			            k++;
			        }
			   			 l++;
			    }
			    if(j<n1)
				{
			      a[i+startrow][l] = Lc[j];
			        j++;
			        l++;
			    }
			    if(k<n2)
				{
			       a[i+startrow][l] = Rc[k];
			        l++;
			        k++;
   				 }
		 }
	    n1=midrow-startrow+1;
		 n2=m-midrow;
	     for(int i=0;i<=n-startcol;i++)
	     {
	     	for(int j=0;j<midrow-startrow+1;j++)
	     	{
	     	    Lr[j]=a[startrow+j][i+startcol];
			 }
			for (int j=0;j<m-midrow;j++)
			{
       			Rr[j] = a[midrow + 1 + j][i+startcol];
       		}
			 int j=0;
			 int k=0;
			 int l=startrow;
			 while (j<n1 && k<n2) {

			        if (Lr[j]<=Rr[k])
					{
			            a[l][i+startcol] =Lr[j];
			            j++;
			        }
			        else
					{
			            a[l][i+startcol] = Rr[k];
			            k++;
			        }
			   			 l++;
			    }
			    if (j<n1)
				{
			        a[l][i+startcol] = Lr[j];
			        j++;
			        l++;
			    }
			    if (k<n2)
				{
			        a[l][i+startcol] = Rr[k];
			        l++;
			        k++;
   				 }
		 }
	}
    void mergesort(int**a,int startrow,int startcol,int m,int n)
	{
		if(startrow>=m  and  startcol>=n)
		  return ;
		  int midcol= (n+startcol)/2;
		  int midrow= (m+startrow)/2;
          mergesort(a,startrow,startcol,midrow,midcol);
         if(midcol<n)
          mergesort(a,startrow,midcol+1,midrow,n);
          if(midrow<m)
          mergesort(a,midrow+1,startcol,m,midcol);
          if(midrow<m and midcol<n)
    	mergesort(a,midrow+1,midcol+1,m,n);
          merge(a,startrow,startcol,m,n,midrow,midcol);
	}
	int main()
	{
		int n,m;
		cin>>m>>n;
		int **a;
		a = new int *[m];
		for(int i=0;i<m;i++)
		    a[i] = new int[n];
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		mergesort(a,0,0,m-1,n-1);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		}
	}
