// Nicole Tome
import java.util.*;
public class cmsc401 {
    private static final Scanner scanner = new Scanner(System.in);
    // Please use these methods to take inputs and write outputs.
    private static Integer readInt() {
        return scanner.nextInt();
    }
    private static String readString() {
        return scanner.next();
    }
    private static Integer[] readIntegerArray(int size) {
        Integer[] array = new Integer[size];
        for (int i = 0; i < size; i++) {
            array[i] = readInt();
        }
        return array;
    }
    private static void printInt(int a) {
        System.out.println(a);
    }
    private static void printString(String s) {
        System.out.println(s);
    }
    public static void main(String[] args) {
//        // reading an Integer
        Integer a = readInt();
//        // writing int output
//        printInt(a);
//
//        // reading a String
//        String s = readString();
//        // writing string output
//        printString(s);
//
//        // reading an Integer Array (you should provide the size)
        Integer[] listOfIntegers = readIntegerArray(a);
        // write your code here
        int largest= -1;
        int secondLargest = -1;
        
        for (int i=0;i<a;i++){
            if(listOfIntegers[i]>largest){
                secondLargest=largest;
                largest=listOfIntegers[i];
            }
            else if(listOfIntegers[i]>secondLargest && listOfIntegers[i]<largest){
                secondLargest=listOfIntegers[i];
            }
        }
        System.out.println(secondLargest);
    }
}
