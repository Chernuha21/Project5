#pragma once
#include<cstdlib>
#include<ctime>
using namespace std;
namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(time(0));
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(367, 213);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add to";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(149, 60);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 347);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(464, 60);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(13, 80);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 84);
			this->listBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(367, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Delete from";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(367, 336);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(166, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Show result";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 507);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Collections::Generic::Stack<int>myStack1;
		int count = 0;
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int size = Convert::ToInt32(textBox1->Text);
		if (count<size)
		{
			int randomValue = rand() % 100;
			myStack1.Push(randomValue);
			listBox1->Items->Insert(0, randomValue.ToString());
			count++;

		}
		else
		{
			MessageBox::Show("Limit is already");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (myStack1.Count > 0)
		{
			myStack1.Pop();
			listBox1->Items->Clear();
			for each (int value in myStack1)
			{

				listBox1->Items->Add(value.ToString());

			}
		}
		else
		{
			listBox1->Items->Add("empty steck");
		}
		}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		int sum = 0;
		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			int value = System::Convert::ToInt32(listBox1->Items[i]);
			if (value >= 10 && value <= 99)
			{
				sum = sum+1;
			}
		}
		MessageBox::Show(sum.ToString());
	}

};
}

