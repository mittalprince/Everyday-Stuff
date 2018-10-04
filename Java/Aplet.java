import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class Aplet extends Applet implements ActionListener{
		TextField tf ;

	public void init() {
		tf = new TextField();
		tf.setBounds(100, 200, 100, 200);

		Button b = new Button("Click Me");
		b.addActionListener(this);
		add(b);
		add(tf);
	}
	public void actionPerformed(ActionEvent e){
		tf.setText("Hello");
	}
}




