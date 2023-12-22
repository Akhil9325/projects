import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class hello{
    public static class calc implements Serializable{
        private int ans,val;
        public calc(int ans,int val){
            this.ans = ans;
            this.val = val;
        }
        public void print(){
            System.out.println("the answer is "+ans+"and the value is"+val);
        }
        public void getter(){
            System.out.println(val);
        }
    }
    public static void main(String[] args){
        try{
        ObjectOutputStream ob = new ObjectOutputStream(new FileOutputStream("D:/Pictures/hello.txt"));
        int num = 4353465;
        ob.writeObject(num);
        ObjectInputStream bo = new ObjectInputStream(new FileInputStream("D:/Pictures/hello.txt"));
        int ans = (int)bo.readObject();
        System.out.println(ans);
      

    }
    catch(Exception e){

    }
}
}