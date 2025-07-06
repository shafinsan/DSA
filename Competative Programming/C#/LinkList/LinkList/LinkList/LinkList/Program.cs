using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkList
{
	internal class Program
	{
		public class Node
		{
			public int data;
			public Node next;

			public Node(int data)
			{
				this.data = data;
				this.next = null;
			}
		}
		public class LinkList
		{
			Node head = null;

			public void InsertAtHead(int data)
			{
				Node temp = new Node(data);
				temp.next = head;
				head = temp;
			}

			public void InsertAtTail(int data)
			{
				Node temp = new Node(data);
				if (head == null)
				{
					head = temp;
					return;
				}
				Node current = head;
				while (current.next != null)
				{
					current = current.next;
				}
				current.next = temp;
			}

			public void InsertAtPosition(int position, int data)
			{
				if (position <= 1 || head == null)
				{
					InsertAtHead(data);
					return;
				}

				Node newNode = new Node(data);
				Node current = head;
				int count = 1;

				while (count < position - 1 && current.next != null)
				{
					current = current.next;
					count++;
				}

				newNode.next = current.next;
				current.next = newNode;
			}

			public void DeleteAtHead()
			{
				if (head == null)
				{
					Console.WriteLine("List is empty");
					return;
				}
				head = head.next;
			}

			public void DeleteAtTail()
			{
				if (head == null)
				{
					Console.WriteLine("List is empty");
					return;
				}
				if (head.next == null)
				{
					head = null;
					return;
				}
				Node current = head;
				while (current.next.next != null)
				{
					current = current.next;
				}
				current.next = null;
			}

			public void DeleteAtPosition(int position)
			{
				if (head == null || position <= 1)
				{
					DeleteAtHead();
					return;
				}

				Node current = head;
				int count = 1;

				while (count < position - 1 && current.next != null)
				{
					current = current.next;
					count++;
				}

				if (current.next == null || current.next.next == null)
				{
					DeleteAtTail();
					return;
				}

				current.next = current.next.next;
			}

			public void Display()
			{
				if (head == null)
				{
					Console.WriteLine("List is empty");
					return;
				}

				Console.Write("List: ");
				Node current = head;
				while (current != null)
				{
					Console.Write(current.data);
					if (current.next != null)
					{
						Console.Write(" -> ");
					}
					current = current.next;
				}
				Console.WriteLine();
			}
		}
		static void Main(string[] args)
		{
			LinkList list = new LinkList();

			while (true)
			{
				Console.WriteLine("\n--- Singly Linked List Menu ---");
				Console.WriteLine("1. Insert at Head");
				Console.WriteLine("2. Insert at Tail");
				Console.WriteLine("3. Insert at Position");
				Console.WriteLine("4. Delete at Head");
				Console.WriteLine("5. Delete at Tail");
				Console.WriteLine("6. Delete at Position");
				Console.WriteLine("7. Display List");
				Console.WriteLine("0. Exit");
				Console.Write("Enter your choice: ");

				int choice = Convert.ToInt32(Console.ReadLine());
				int data, position;

				switch (choice)
				{
					case 1:
						Console.Write("Enter value: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.InsertAtHead(data);
						break;
					case 2:
						Console.Write("Enter value: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.InsertAtTail(data);
						break;
					case 3:
						Console.Write("Enter position: ");
						position = Convert.ToInt32(Console.ReadLine());
						Console.Write("Enter value: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.InsertAtPosition(position, data);
						break;
					case 4:
						list.DeleteAtHead();
						break;
					case 5:
						list.DeleteAtTail();
						break;
					case 6:
						Console.Write("Enter position: ");
						position = Convert.ToInt32(Console.ReadLine());
						list.DeleteAtPosition(position);
						break;
					case 7:
						list.Display();
						break;
					case 0:
						Console.WriteLine("Exiting...");
						return;
					default:
						Console.WriteLine("Invalid choice.");
						break;
				}
			}
		}
	}
}
