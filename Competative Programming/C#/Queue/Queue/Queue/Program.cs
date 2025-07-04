using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Queue
{
	internal class Program
	{
		public class Queue{
			int front;
			int rear;
			int[] arr;
			int size;
			public Queue(int size)
			{
				this.size = size;
				arr = new int[size];
				front = -1;
				rear = -1;
			}
			//push
			public void Push(int x)
			{
				if(front==-1 && rear == -1)
				{
					front = rear = 0;
					arr[front] = x;
					return;
				}
				else if (isFull())
				{
					Console.WriteLine("Queue is full");
					return;
				}
				rear = (rear + 1) % size;
				arr[rear] = x;
				return;
			}
			//pop
			public int Pop()
			{
				if (isEmpty())
				{
					Console.WriteLine("Queue is empty");
					return -1;
				}
				if (rear == front)
				{
					rear = front = -1;
					return -1;
				}
				int ans = arr[front];
				front = (front + 1) % size;
				return ans;

			}
			//is empty
			public bool isEmpty()
			{
				return (rear==-1 && front==-1)?true:false;
			}
			//is full
			public bool isFull()
			{
				return ((rear + 1) % size)==front?true:false;
			}
			//top
			public int Front()
			{
				if (isEmpty())
				{
					return -1;
				}
				return arr[front];
			}
			//last
			public int Rear()
			{
				if (isEmpty())
				{
					return -1;
				}
				return arr[rear];
			}
			//dispaly
			public void Display()
			{
				if (isEmpty())
				{
					Console.WriteLine("Queue is empty");
					return;
				}
				if (front <= rear)
				{
					for(int i = front; i <= rear; i++)
					{
						Console.WriteLine("Queue :" + arr[i]);
					}
					return;
				}
				for (int i = front; i < size; i++)
				{
					Console.WriteLine("Queue :" + arr[i]);
				}
				for (int i = 0; i < front; i++)
				{
					Console.WriteLine("Queue :" + arr[i]);
				}
				return;
			}
		}
		static void Main(string[] args)
		{
			Console.Write("Enter queue size: ");
			int size = int.Parse(Console.ReadLine());
			Queue q = new Queue(size);

			while (true)
			{
				Console.WriteLine("\n1. Push (Enqueue)");
				Console.WriteLine("2. Pop (Dequeue)");
				Console.WriteLine("3. Front (Peek)");
				Console.WriteLine("4. Rear");
				Console.WriteLine("5. Display");
				Console.WriteLine("6. Exit");
				Console.Write("Enter choice: ");

				int choice = int.Parse(Console.ReadLine());

				switch (choice)
				{
					case 1:
						Console.Write("Enter value to push: ");
						int val = int.Parse(Console.ReadLine());
						q.Push(val);
						break;

					case 2:
						int popped = q.Pop();
						if (popped != -1)
							Console.WriteLine("Popped: " + popped);
						break;

					case 3:
						int front = q.Front();
						if (front != -1)
							Console.WriteLine("Front element: " + front);
						break;

					case 4:
						int rear = q.Rear();
						if (rear != -1)
							Console.WriteLine("Rear element: " + rear);
						break;

					case 5:
						q.Display();
						break;

					case 6:
						Environment.Exit(0);
						break;

					default:
						Console.WriteLine("Invalid choice!");
						break;
				}
			}
		}
	}
}
