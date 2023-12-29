import javax.swing.JFileChooser;
import java.io.*;
import javax.swing.*;

public class frame{
    public static class framed extends JFrame{
        public framed(){
            setTitle("akhil");
            setBounds(50,50,400,400);
            setVisible(true);
            setLayout(null);
            JFileChooser jb = new JFileChooser();
            jb.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
            int result = jb.showOpenDialog(jb);
            File obj = jb.getSelectedFile();
            add(jb);
        }
    }
     public static void main(String[] args){
        new framed();
     }
}
