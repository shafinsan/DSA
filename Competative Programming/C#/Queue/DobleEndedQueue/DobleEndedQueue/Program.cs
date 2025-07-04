using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DobleEndedQueue
{
	internal class Program
	{
		public class Deque
		{
			int front;
			int rear;
			int[] arr;
			int size;
			public Deque(int size)
			{
				this.size = size;
				arr = new int[size];
				front = -1;
				rear = -1;
			}
			//push
			public void PushFront(int x)
			{
				if (front == -1 && rear == -1)
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
				if (front == 0)
				{
					front = size - 1;
					arr[front] = x;	
					return;
				}
				front = (front - 1) % size;
				arr[front] = x;
				return;
			}
			public void PushRear(int x)
			{
				if (front == -1 && rear == -1)
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
			public int PopFront()
			{
				if (isEmpty())
				{
					Console.WriteLine("Queue is empty");
					return -1;
				}
				if (rear == front)
				{
					int value = arr[rear];
					rear = front = -1;
					return value;
				}
				int ans = arr[front];
				front = (front + 1) % size;
				return ans;

			}
			public int PopRear()
			{
				if (isEmpty())
				{
					Console.WriteLine("Queue is empty");
					return -1;
				}
				if (rear == front)
				{
					int value = arr[rear];
					rear = front = -1;
					return value;
				}
				if (rear == 0)
				{
					int val=arr[rear];
					rear = size - 1;
					return val;
				}
				int ans = arr[rear];
				rear = (rear - 1) % size;
				return ans;

			}
			//is empty
			public bool isEmpty()
			{
				return (rear == -1 && front == -1) ? true : false;
			}
			//is full
			public bool isFull()
			{
				return ((rear + 1) % size) == front ? true : false;
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
					Console.WriteLine("Deque is empty");
					return;
				}

				Console.Write("Deque: ");
				int i = front;
				while (true)
				{
					Console.Write(arr[i] + " ");
					if (i == rear)
						break;
					i = (i + 1) % size;
				}
				Console.WriteLine();
			}
		}
		static void Main(string[] args)
		{
			Console.Write("Enter Deque size: ");
			int size = int.Parse(Console.ReadLine());
			Deque dq = new Deque(size);

			while (true)
			{
				Console.WriteLine("\n1. PushFront");
				Console.WriteLine("2. PushRear");
				Console.WriteLine("3. PopFront");
				Console.WriteLine("4. PopRear");
				Console.WriteLine("5. Front");
				Console.WriteLine("6. Rear");
				Console.WriteLine("7. Display");
				Console.WriteLine("8. Exit");
				Console.Write("Enter choice: ");

				int choice = int.Parse(Console.ReadLine());

				switch (choice)
				{
					case 1:
						Console.Write("Enter value to push at front: ");
						int valFront = int.Parse(Console.ReadLine());
						dq.PushFront(valFront);
						break;

					case 2:
						Console.Write("Enter value to push at rear: ");
						int valRear = int.Parse(Console.ReadLine());
						dq.PushRear(valRear);
						break;

					case 3:
						int poppedFront = dq.PopFront();
						if (poppedFront != -1)
							Console.WriteLine("Popped from front: " + poppedFront);
						break;

					case 4:
						int poppedRear = dq.PopRear();
						if (poppedRear != -1)
							Console.WriteLine("Popped from rear: " + poppedRear);
						break;

					case 5:
						int front = dq.Front();
						if (front != -1)
							Console.WriteLine("Front element: " + front);
						break;

					case 6:
						int rear = dq.Rear();
						if (rear != -1)
							Console.WriteLine("Rear element: " + rear);
						break;

					case 7:
						dq.Display();
						break;

					case 8:
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
