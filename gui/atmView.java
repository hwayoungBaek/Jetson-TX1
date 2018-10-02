package test;

import javax.swing.JButton;
import javax.swing.JFrame;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class atmView extends JFrame implements ActionListener{
	private JButton btnStart,btnHelp;

	public atmView(String title) {
		
		/*������ ����*/
		// - ������ ���α׷��� ������ ������ ���� ��ư�� ������
		// ȭ�鿡�� �������� ������, ������ ���α׷��� ��������� ����.
		// - �������� ���� ��ư���� ���α׷��� �Բ� �����ϱ� ���� �޼ҵ� ȣ��.
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(500,400);
		setTitle(title);
		
		/*��ư ����*/
		//setLayout - ��ġ�����ڰ� ���� �����̳� �����
		setLayout(null);
		btnStart = new JButton("Start");
		btnHelp = new JButton("?");
		// ��ư�� ������ ���ο� ���θ� �˾ƺ���
		// Dimension d = btnStart.getPreferredSize(); 
		// btnStart.setSize(d);
		btnStart.setSize(100, 30);
		btnHelp.setSize(50,30);
		//btnHelp.setBackground(Color.BLACK);
	
		btnStart.setLocation(200, 170);
		btnHelp.setLocation(430,10);
		add(btnStart);
		add(btnHelp);
		
		
		/*��ư�� �̺�Ʈ ������ �߰�*/
		btnStart.addActionListener(this);
		btnHelp.addActionListener(this);
		
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt) {
		//Ŭ���� ��ư�� �̸��� ����
		String strCmd = evt.getActionCommand();
		
		//���̺� Ŭ���� ��ư�� �̸��� ����
		if(strCmd.equals("Start")) {
			//btnStart.setText("��ư ����");
			callCommand("ipconfig");
		}else if(strCmd.equals("?")) {
			btnHelp.setText("��ư");
		}
	}
	
	// ������ ��ɾ� �����Ű�� �Լ�
	public void callCommand(String command) {
		
		Runtime rt = Runtime.getRuntime();
		
		try {
			Process p = rt.exec(command);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("�ڹ� �׽�Ʈ");
		
		atmView av=new atmView("ATM GUI");
		
	
	}
}


