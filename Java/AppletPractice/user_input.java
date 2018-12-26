import java.applet.*;
import java.awt.*;

public class user_input extends Applet{
	TextField t1, t2;
	public void init(){
		t1 = new TextField(5);
		t2 = new TextField(5);

		add(t1);
		add(t2);
	}

	public void paint(Graphics g){
		int x = 0;
		x = Integer.parseInt(t1.getText());
		t2.setText(String.valueOf(x*x));
	}
}