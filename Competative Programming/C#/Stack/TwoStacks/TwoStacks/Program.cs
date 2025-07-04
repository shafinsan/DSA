using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TwoStacks
{
	internal class Program
	{
		public class TwoStacks
		{
			int size;
			int top1;
			int top2;
			int[] arr;
			public TwoStacks(int size)
			{
				this.size = size;
				top1 = -1;
				top2 = size;
				arr = new int[size];
			}
			public void Push1(int x)
			{
				if (top2 - top1 > 1)
				{
					top1++;
					arr[top1] = x;
					return;
				}
				return;
			}

			// Push into Stack 2
			public void Push2(int x)
			{
				if (top2 - top1 > 1)
				{
					top2--;
					arr[top2] = x;
					return;
				}
				return;
			}

			// Pop from Stack 1
			public int Pop1()
			{
				if (top1 == -1)
				{
					return -1;
				}
				int ans = arr[top1];
				top1--;
				return ans;
			}

			// Pop from Stack 2
			public int Pop2()
			{
				if (top2 == size)
				{
					return -1;
				}
				int ans =arr[top2];
				top2++;
				return ans;
			}
		}
		static void Main(string[] args)
		{
			var stacks = new TwoStacks(100);

			// Sample test input
			stacks.Push1(2);
			stacks.Push1(3);
			stacks.Push2(4);

			Console.Write(stacks.Pop1()+" "); // Output: 3
			Console.Write(stacks.Pop2()+" "); // Output: 4
			Console.Write(stacks.Pop2()); // Output: -1
		}
	}
}
