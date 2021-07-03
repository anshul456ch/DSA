import java.util.*;
import java.io.*;
public class kadanes
{

public static int solution(int[] arr)
{
int currentSum=arr[0];
int overallSum=arr[0];
for(int i=1;i<arr.length;i++)
{
if(currentSum>=0) currentSum+=arr[i];
else currentSum=arr[i];
if(currentSum>overallSum) overallSum=currentSum;
}
return overallSum;
}


public static void main(String gg[])
{
System.out.println("Enter size of array");
Scanner sc=new Scanner(System.in);
int num=sc.nextInt();
int[] arr=new int[num];
System.out.println("Enter elements of array");
for(int i=0;i<arr.length;i++)
{
arr[i]=sc.nextInt();
}
System.out.println("Max sum of subarray is : ");
System.out.println(solution(arr));
}
}