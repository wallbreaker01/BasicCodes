import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Calculator implements ActionListener{

    JFrame frame;
    JTextField textfield;
    JButton[] numberButtons = new JButton[10];
    JButton[] functionButtons = new JButton[11];
    JButton addButton,subButton,mulButton,divButton;
    JButton decButton, equButton,delButton,clrButton,negButton,sqrtButton,prcntButton;
    JPanel panel;
    Font myfont = new Font("Serif", Font.CENTER_BASELINE,30);
    Font hehefont = new Font("Serif", Font.TRUETYPE_FONT,23);
    double num1 = 0,num2 = 0,result = 0;
    char operator;

    Calculator(){

        frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(410,620);
        frame.setLayout(null);
        //frame.getContentPane().setBackground(Color.GRAY);


        textfield = new JTextField();
        textfield.setBounds(25,25,350,70);
        textfield.setFont(myfont);
        textfield.setEnabled(false);

        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("*");
        divButton = new JButton("/");
        decButton = new JButton(".");
        equButton = new JButton("=");
        delButton = new JButton("Delete");
        clrButton = new JButton("Clear");
        negButton = new JButton("(-)");
        sqrtButton = new JButton("sqrt");
        prcntButton = new JButton("%");


        functionButtons[0] = addButton;
        functionButtons[1] = subButton;
        functionButtons[2] = mulButton;
        functionButtons[3] = divButton;
        functionButtons[4] = decButton;
        functionButtons[5] = equButton;
        functionButtons[6] = delButton;
        functionButtons[7] = clrButton;
        functionButtons[8] = negButton;
        functionButtons[9] = sqrtButton;
        functionButtons[10] = prcntButton;

        for (int i = 0 ; i < 11 ; i++){
            functionButtons[i].addActionListener(this);
            functionButtons[i].setFont(hehefont);
            functionButtons[i].setFocusable(false);
            functionButtons[i].setBackground(Color.LIGHT_GRAY);
        }
        for (int i = 0 ; i < 10 ; i++){
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].addActionListener(this);
            numberButtons[i].setFont(hehefont);
            numberButtons[i].setFocusable(false);
            numberButtons[i].setBackground(Color.LIGHT_GRAY);
        }
        addButton.setBackground(Color.RED);
        subButton.setBackground(Color.YELLOW);
        equButton.setBackground(Color.BLUE);

        sqrtButton.setBounds(50,430,100,60);
        negButton.setBounds(150,430,100,60);
        prcntButton.setBounds(250,430,100,60);
        delButton.setBounds(50,500,150,60);
        clrButton.setBounds(200,500,150,60);

        panel = new JPanel();
        panel.setBounds(50,100,300,300);
        panel.setLayout(new GridLayout(4,4,10,10));
        //panel.setBackground(Color.GRAY);

        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(divButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(mulButton);
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(subButton);
        panel.add(decButton);
        panel.add(numberButtons[0]);
        panel.add(equButton);
        panel.add(addButton);

        frame.add(panel);
        frame.add(prcntButton);
        frame.add(negButton);
        frame.add(delButton);
        frame.add(clrButton);
        frame.add(sqrtButton);
        frame.add(textfield);
        frame.setVisible(true);
    }
    public static void main(String[] arg) {

        Calculator calc = new Calculator();
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        for (int i = 0 ; i < 10 ; i++){
            if(e.getSource() == numberButtons[i]){
                textfield.setText(textfield.getText().concat(String.valueOf(i)));
            }
        }
        if(e.getSource() == decButton){
            textfield.setText(textfield.getText().concat(String.valueOf(".")));
        }
        if(e.getSource() == addButton){
            num1 = Double.parseDouble(textfield.getText());
            operator = '+';
            textfield.setText("");
        }
        if(e.getSource() == subButton){
            num1 = Double.parseDouble(textfield.getText());
            operator = '-';
            textfield.setText("");
        }
        if(e.getSource() == mulButton){
            num1 = Double.parseDouble(textfield.getText());
            operator = '*';
            textfield.setText("");
        }
        if(e.getSource() == divButton){
            num1 = Double.parseDouble(textfield.getText());
            operator = '/';
            textfield.setText("");
        }
        if(e.getSource() == prcntButton){
            num1 = Double.parseDouble(textfield.getText());
            operator = '%';
            textfield.setText("");
        }
        if(e.getSource() == equButton){
            num2 = Double.parseDouble(textfield.getText());

            switch (operator){
                case '+' :
                    result = num1 + num2;
                    break;
                case '-' :
                    result = num1 - num2;
                    break;
                case '*' :
                    result = num1 * num2;
                    break;
                case '/' :
                    result = num1 / num2;
                    break;
                case '%' :
                    result = num1 * num2/100;
                    break;
            }
            textfield.setText(String.valueOf(result));
            num1 = result;
        }
        if(e.getSource() == clrButton){
            textfield.setText("");
        }
        if(e.getSource() == delButton){
            String string = textfield.getText();
            textfield.setText("");
            for (int i = 0 ; i < string.length()-1 ; i++){
                textfield.setText(textfield.getText()+string.charAt(i));
            }

        }
        if(e.getSource() == negButton){
            double temp = Double.parseDouble(textfield.getText());
            temp *= -1;
            textfield.setText(String.valueOf(temp));
        }
        if(e.getSource() == sqrtButton){
            num1 = Double.parseDouble(textfield.getText());
            //operator = '√';
            result = Math.sqrt(num1);
            textfield.setText(String.valueOf(result));
        }
//        if(e.getSource() == prcntButton){
//            num2 = Double.parseDouble(textfield.getText());
//            result = num1 * num2 / 100;
//            textfield.setText(String.valueOf(result));
//        }
    }
}
