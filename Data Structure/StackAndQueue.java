package data_structure;

public class StackAndQueue {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//StackAndQueue sq = new StackAndQueue();
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

}
