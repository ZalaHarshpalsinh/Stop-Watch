#pragma once
#include<Windows.h>
#include <string>
using namespace std;

namespace Stop_watch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	class My_Stop_Watch
	{
		int hour;
		int minutes;
		int seconds;
		bool is_on;

	public:
		My_Stop_Watch() :hour(0), minutes(0), seconds(0), is_on(false)
		{}
		void start()
		{
			is_on = true;
		}
		void stop()
		{
			is_on = false;
		}
		bool on()
		{
			return is_on;
		}
		string get_time()
		{
			seconds++;
			if (seconds == 60)
			{
				minutes++;
				seconds = 00;
			}
			if (minutes == 60)
			{
				hour++;
				minutes = 00;
			}
			string sec = to_string(seconds);
			if (sec.length() == 1)
			{
				sec = "0" + sec;
			}
			string min = to_string(minutes);
			if (min.length() == 1)
			{
				min = "0" + min;
			}
			string hr = to_string(hour);
			if (hr.length() == 1)
			{
				hr = "0" + hr;
			}
			string time = hr + ":" + min + ":" + sec;
			return time;
		}
		void reset_time()
		{
			hour = 0;
			minutes = 0;
			seconds = 0;
		}
	}mysw;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Initialize_My_Component();
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
	private: System::Windows::Forms::Label^ lbTime;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btReset;
	private: System::Windows::Forms::Button^ btPause;
	private: System::Windows::Forms::Button^ btStart;
	//private: Stopwatch^ stopwatch = gcnew Stopwatch();
	private: Timer^ timer = gcnew Timer();

	protected:

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
		void Initialize_My_Component(void)
		{
			timer->Interval = 1000;
			timer->Tick += gcnew EventHandler(this, &MyForm::update_time);
		}
		void InitializeComponent(void)
		{
			this->lbTime = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btReset = (gcnew System::Windows::Forms::Button());
			this->btPause = (gcnew System::Windows::Forms::Button());
			this->btStart = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbTime
			// 
			this->lbTime->AutoSize = true;
			this->lbTime->Font = (gcnew System::Drawing::Font(L"Digital-7 Mono", 72, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbTime->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lbTime->Location = System::Drawing::Point(151, 23);
			this->lbTime->MinimumSize = System::Drawing::Size(514, 120);
			this->lbTime->Name = L"lbTime";
			this->lbTime->Size = System::Drawing::Size(514, 120);
			this->lbTime->TabIndex = 0;
			this->lbTime->Text = L"00:00:00";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				205)));
			this->tableLayoutPanel1->Controls->Add(this->btReset, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->btPause, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->btStart, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(107, 193);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(602, 58);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// btReset
			// 
			this->btReset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btReset->Font = (gcnew System::Drawing::Font(L"Calisto MT", 19.8F, System::Drawing::FontStyle::Bold));
			this->btReset->Location = System::Drawing::Point(399, 3);
			this->btReset->MaximumSize = System::Drawing::Size(200, 52);
			this->btReset->MinimumSize = System::Drawing::Size(200, 52);
			this->btReset->Name = L"btReset";
			this->btReset->Size = System::Drawing::Size(200, 52);
			this->btReset->TabIndex = 2;
			this->btReset->Text = L"Reset";
			this->btReset->UseVisualStyleBackColor = false;
			this->btReset->Click += gcnew System::EventHandler(this, &MyForm::btReset_Click);
			// 
			// btPause
			// 
			this->btPause->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btPause->Font = (gcnew System::Drawing::Font(L"Calisto MT", 19.8F, System::Drawing::FontStyle::Bold));
			this->btPause->Location = System::Drawing::Point(201, 3);
			this->btPause->MaximumSize = System::Drawing::Size(192, 52);
			this->btPause->MinimumSize = System::Drawing::Size(192, 52);
			this->btPause->Name = L"btPause";
			this->btPause->Size = System::Drawing::Size(192, 52);
			this->btPause->TabIndex = 1;
			this->btPause->Text = L"Pause";
			this->btPause->UseVisualStyleBackColor = false;
			this->btPause->Click += gcnew System::EventHandler(this, &MyForm::btPause_Click);
			// 
			// btStart
			// 
			this->btStart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btStart->Font = (gcnew System::Drawing::Font(L"Calisto MT", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btStart->Location = System::Drawing::Point(3, 3);
			this->btStart->MaximumSize = System::Drawing::Size(192, 52);
			this->btStart->MinimumSize = System::Drawing::Size(192, 52);
			this->btStart->Name = L"btStart";
			this->btStart->Size = System::Drawing::Size(192, 52);
			this->btStart->TabIndex = 0;
			this->btStart->Text = L"Start";
			this->btStart->UseVisualStyleBackColor = false;
			this->btStart->Click += gcnew System::EventHandler(this, &MyForm::btStart_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(834, 319);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->lbTime);
			this->MaximumSize = System::Drawing::Size(852, 366);
			this->MinimumSize = System::Drawing::Size(852, 366);
			this->Name = L"MyForm";
			this->Text = L"Stop Watch";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		// Calculate elapsed time and update the label
		TimeSpan elapsed = stopwatch->Elapsed;
		lbTime->Text = elapsed.ToString("hh\\:mm\\:ss");
	}*/
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		lbTime->Text = "00:00:00";
	}
	private: System::Void btStart_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		timer->Start();
		mysw.start();
	}
	private: System::Void btPause_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//stopwatch->Stop();
		mysw.stop();
	}
	private: System::Void btReset_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//stopwatch->Reset();
		mysw.reset_time();
		lbTime->Text = "00:00:00";
	}
	private: void update_time(System::Object^ sender, System::EventArgs^ e)
	{
		if (mysw.on())
		{
			String^ time = gcnew String(mysw.get_time().data());
			lbTime->Text = time;
		}
	}
};

}
