/*

Cat Got Bored <@_@>

*/

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
//import java.math.BigInteger;
import java.util.StringTokenizer;

public class java_template {
	 public static void main(String[] args) {
	      fastScanner fs = new fastScanner();
	      //To simulate EOF
	      //Scanner sc = new Scanner(System.in);
	      //while(sc.hasNext())
	      out = new PrintWriter(new BufferedOutputStream(System.out));

	      // Usage-------------------------------------

	      /**
	      int n      = fs.nextInt();        // read input as integer
	      long k     = fs.nextLong();       // read input as long
	      double d   = fs.nextDouble();     // read input as double
	      String str = fs.next();           // read input as String
	      String s   = fs.nextLine();       // read whole line as String




	      out.println();                    // print from PrintWriter
	      **/




	      // Stop writing your solution here. -------------------------------------
	      out.close();
	   }



	   //-----------PrintWriter for faster output---------------------------------
	   public static PrintWriter out;

	   //-----------FastScanner class for faster input----------
	   public static class fastScanner {
	      BufferedReader BuffRead;
	      StringTokenizer StrToc;

	      public fastScanner() {
	         BuffRead = new BufferedReader(new InputStreamReader(System.in));
	      }

	      String next() {
	          while (StrToc == null || !StrToc.hasMoreElements()) {
	              try {
	                  StrToc = new StringTokenizer(BuffRead.readLine());
	              } catch (IOException e) {
	                  e.printStackTrace();
	              }
	          }
	          return StrToc.nextToken();
	      }

	      int nextInt() {
	          return Integer.parseInt(next());
	      }

	      long nextLong() {
	          return Long.parseLong(next());
	      }

	      double nextDouble() {
	          return Double.parseDouble(next());
	      }
	      /*
	      BigInteger nextBigInteger(){
	    	  return new BigInteger(next().toString());
	      }
	      */
	      String nextLine(){
	          String str = "";
		  try {
		     str = BuffRead.readLine();
		  } catch (IOException e) {
		     e.printStackTrace();
		  }
		  return str;
	      }

	   }
	   //--------------------------------------------------------

}
