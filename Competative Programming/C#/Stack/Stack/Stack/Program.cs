using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
	internal class Program
	{
		public class my_stack
		{
			public int top = 5;
			int[] arr;
			int size;
			public my_stack(int size)
			{
				this.size = size;
				top = -1;
				arr = new int[size];
			}
			public void push(int value)
			{
				if (top == size - 1)
				{
					Console.WriteLine("Stack overflow");
					return;
				}
				top++;
				arr[top] = value;
				return;

			}
			public void pop()
			{
				if (!isEmpty())
				{
					top--;
					return;
				}
				Console.WriteLine("Stack underflow");
				return;
			}
			public int my_top()
			{
				if (!isEmpty())
				{
					return arr[top];
				}
				return -1;
			}
			public bool isEmpty()
			{
				if (top == -1)
				{
					return true;
				}
				return false;
			}
			public void display()
			{
				if (!isEmpty())
				{
					for (int i = 0; i <= top; i++)
					{
						Console.WriteLine("Stack vlaue is " + arr[i]);
					}
					return;
				}
				Console.WriteLine("Stack underflow");

			}
		}
		static void Main(string[] args)
		{
			my_stack st = new my_stack(5);
			st.push(1);
			st.display();
			st.push(2);
			st.push(3);
			st.push(4);
			st.display();
			st.push(5);
			st.display();
			st.push(6);
			st.display();
			st.pop();
			Console.WriteLine("After pop top value is " + st.my_top());
			st.pop();
			st.pop();
			st.pop();
			st.display();
			st.pop();
			st.pop();
			st.pop();
			st.display();
		}
	}
}
