using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoubleEndedLinklist
{
	public class LinkList
	{
		Node head = null;
		Node tail = null;
		public void InsertAtHead(int data)
		{
			Node temp = new Node(data);
			if (head==null || tail==null)
			{
				head=tail= temp;
				return;
			}
			temp.Next = head;
			head.Previous = temp;
			head = temp;
			return;

		}
		public void insertAtTail(int data)
		{
			Node temp = new Node(data);
			if (head==null || tail == null)
			{
				head = tail = temp;
				return;
			}
			
			tail.Next = temp;
			temp.Previous = tail;
			tail = temp;
		}
		public void deleteAtHead()
		{
			if (head == null)
			{
				Console.WriteLine("List is empty");
				return;
			}
			if (head == tail)
			{
				// Only one node
				head = tail = null;
				return;
			}
		
			
			Node temp = head;
			head = temp.Next;
			head.Previous = null;
			temp.Next = null;
			temp.Previous = null;

		}
		public void DeleteAtTail()
		{
			if (tail == null)
			{
				Console.WriteLine("List is empty");
				return;
			}
			if (head == tail)
			{
				// Only one node
				head = tail = null;
				return;
			}
			Node pre=tail;
			tail = pre.Previous;
			pre.Previous = null;
			tail.Next = null;
		}
		public void InsertAtAnyPosition(int position,int data)
		{
			Node temp = head;
			int cnt = 1;
			if (position <= 1)
			{
				InsertAtHead(data);
				return;
			}
			while (cnt < position - 1)
			{
				if (temp.Next.Next == null)
				{
					insertAtTail(data);
					return;
				}
				temp = temp.Next;
				cnt++;
			}
			Node newNode = new Node(data);
			Node nextNode = temp.Next;
			nextNode.Previous = newNode;
			newNode.Previous = temp;
			newNode.Next = nextNode;
			temp.Next = newNode;
			return;

		}
		public void DeleteAtAnyPosition(int postion)
		{
			Node temp = head;
			if (postion <= 1 || temp.Next==null)
			{
				deleteAtHead();
				return;
			}
	
			int cnt = 1;
			while (cnt < postion )
			{
		
				if (temp.Next.Next == null)
				{
					
					DeleteAtTail();
					return;
				}
				temp = temp.Next;
				cnt++;
			}
			Node PreNode = temp.Previous;
			Node next = temp.Next;
			PreNode.Next= next;
			next.Previous = PreNode;
			temp.Previous = null;
			temp.Next=null;
		}

		public void Display()
		{
			if (head == null && tail == null)
			{
				Console.WriteLine("List is Empty");
				return;
			}

			Console.WriteLine("Forward:");
			Node temp = head;
			while (temp != null)
			{
				Console.Write(temp.data);
				if (temp.Next != null)
				{
					Console.Write(" -> ");
				}
				temp = temp.Next;
			}

			Console.WriteLine("\nReverse:");
			Node temp2 = tail;
			while (temp2 != null)
			{
				Console.Write(temp2.data);
				if (temp2.Previous != null)
				{
					Console.Write(" -> ");
				}
				temp2 = temp2.Previous;
			}
			return;
		}
	}
}
