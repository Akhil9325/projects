import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.ActionListener;
import java.awt.*;

public class App{
   public static class frame extends JFrame{
      public frame(){
      setTitle("mera project");
      setLayout(null);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setResizable(true);
      setBounds(100,100,400,450);
      setVisible(true);
      JTextArea jt = new JTextArea("",2,50);
      jt.setBounds(30,20,250,50);
      add(jt);
      int m = 2;
      int n = 5;
      int x=0,y=100;
      String[] arr = {"+","-","*","/","AC"};
      for(int i = 0;i<m;i++){
         x = 30;
         for(int j = 0;j<n;j++){
            JButton bt = new JButton(""+(j+(i==0?i:5)));
            bt.setBounds(x,y,60,60);
            x+=60;
            bt.addActionListener(new ActionListener(){
               public void actionPerformed(ActionEvent e){
                  jt.append(bt.getText());
               }}
            );
            add(bt);
         }
         y+=60;
      }
      y+=60;

      for(int i = 0;i<1;i++){
         x=30;
         for(int j = 0;j<4;j++){
            JButton bt = new JButton(""+arr[j]);
            bt.setBounds(x,y,60,60);
            x+=60;
            bt.addActionListener(new ActionListener(){
               public void actionPerformed(ActionEvent e){
                  jt.append(bt.getText());
               }}
         );
            add(bt);
         }
      }
      JButton btn = new JButton("AC");
      btn.setBounds(x,y,60,60);
      btn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e){
            jt.setText(" ");
         }
      });
      add(btn);

      }}
   
   public static void main(String[] args){
      new frame();
   }
}
