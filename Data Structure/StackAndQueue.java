package data_structure;

public class StackAndQueue {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Stack s = new Stack(5);
		System.out.println(s.isEmpty());
		s.pop();
		s.push("H");
		s.push("e");
		s.push("l");
		s.push("l");
		s.pop();
		s.push("o");
		s.push("!");
		
		Queue q = new Queue(5);
		q.enqueue("A");
		q.enqueue("B");
		q.enqueue("C");
		q.enqueue("D");
		q.enqueue("E");
		q.enqueue("F");
		q.enqueue("G");
		q.dequeue();
	}
	
	public static class Stack {
		private String[] stack;
		private int stackSize;
		private int top;
		
		Stack(int size) {
			stackSize = size;
			stack = new String[size];
			top = -1;
		}
		
		public boolean isEmpty() {
			if(top == -1)
				return true;
			else
				return false;
		}
		
		public void push(String x) {
			if(top == stackSize - 1)
				System.out.println("ERROR: Stack Overflow!");
			else {
				top = top + 1;
				stack[top] = x;
			}
		}
		
		public void pop() {
			if(isEmpty())
				System.out.println("ERROR: Stack Underflow!");
			else {
				System.out.println(stack[top] + " has been deleted.");
				top = top - 1;
			}
		}
	}
	
	public static class Queue {
		private String[] queue;
		private int queueSize;
		private int head;
		private int tail;
		
		Queue(int size) {
			queueSize = size;
			queue = new String[size];
			head = 0;
			tail = 0;
		}
		
		public void enqueue(String x) {
			queue[tail] = x;
			if(tail == queueSize - 1)
				tail = 0;
			else
				tail = tail + 1;
			System.out.println(x + " enqueue, tail index: " + tail);
		}
		
		public void dequeue() {
			String x = queue[head];
			if(head == queueSize - 1)
				head = 0;
			else
				head = head + 1;
			System.out.println(x + " dequeue, head index: " + head);
		}
	}

}
