using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoubleEndedLinklist
{
	internal class Program
	{
		static void Main(string[] args)
		{
			LinkList list = new LinkList();

			while (true)
			{
				Console.WriteLine("\n--- Doubly Linked List Menu ---");
				Console.WriteLine("1. Insert at Head");
				Console.WriteLine("2. Insert at Tail");
				Console.WriteLine("3. Insert at Any Position");
				Console.WriteLine("4. Delete at Head");
				Console.WriteLine("5. Delete at Tail");
				Console.WriteLine("6. Delete at Any Position");
				Console.WriteLine("7. Display List");
				Console.WriteLine("0. Exit");
				Console.Write("Enter your choice: ");

				int choice = Convert.ToInt32(Console.ReadLine());
				int data, position;

				switch (choice)
				{
					case 1:
						Console.Write("Enter value to insert at head: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.InsertAtHead(data);
						break;

					case 2:
						Console.Write("Enter value to insert at tail: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.insertAtTail(data);
						break;

					case 3:
						Console.Write("Enter position: ");
						position = Convert.ToInt32(Console.ReadLine());
						Console.Write("Enter value to insert: ");
						data = Convert.ToInt32(Console.ReadLine());
						list.InsertAtAnyPosition(position, data);
						break;

					case 4:
						list.deleteAtHead();
						break;

					case 5:
						list.DeleteAtTail();
						break;

					case 6:
						Console.Write("Enter position to delete: ");
						position = Convert.ToInt32(Console.ReadLine());
						list.DeleteAtAnyPosition(position);
						break;

					case 7:
						list.Display();
						break;

					case 0:
						Console.WriteLine("Exiting...");
						return;

					default:
						Console.WriteLine("Invalid choice. Try again.");
						break;
				}
			}







		}
	}
}
