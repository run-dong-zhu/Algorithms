package com.datastructure;

import java.util.ArrayList;
import java.util.Scanner;

public class StringList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StringList sl = new StringList();
		System.out.println("Please enter a group of numbers:");
		Scanner input = new Scanner(System.in);
		String elements = input.nextLine();
		input.close();
		
		for(char elem : elements.toCharArray()) {
			sl.insert(Character.toString(elem));
		}
		
		System.out.println(sl.toString());
		
		System.out.println(sl.search("c"));
		System.out.println(sl.search("g"));
		/*
		System.out.println("Please enter a number to search:");
		input = new Scanner(System.in);
		sl.search(input.toString());
		*/
	}

	private ArrayList<String> arrList;  
	private int count; 
	
	StringList() {
		arrList = new ArrayList<String>();
		count = 0;
	}
	
	public void insert(String str) {
		if(count == 0) {
			arrList.add(str);
			count++;
		}
		else {
			int index = 0;
			while(index < count && str.compareTo(arrList.get(index)) > 0) {
				index++;
			}
			
			if(arrList.contains(str)) {
				arrList.set(index, str);
			}
			else {
				arrList.add(index, str);
				count++;
			}
		}
	}
	
	public String toString() {
		String str = "";
		for(int index=0; index < arrList.size(); index++) {
			str += arrList.get(index);
		}
		return str;
	}
	
	public int search(String str) {
		for(int index = 0; index < count; index++) {
			if(arrList.get(index).compareTo(str) == 0) {
				return index;
			}
		}
		return -1;
	}

}
