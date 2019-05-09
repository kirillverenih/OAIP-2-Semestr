#pragma once
#include <math.h>
#include <chrono>
#include <Windows.h>
#include <random>
namespace Graph
{

	long double fact(int N)
	{
		if (N < 0)
			return 0;
		if (N == 0)
			return 1; 
		else
			return N * fact(N - 1);
	}

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ImageList^  imageList1;
	protected:

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(2, 13);
			this->chart1->Margin = System::Windows::Forms::Padding(4);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(812, 369);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(473, 660);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(192, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Построить график";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(419, 417);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Запуск анимации";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(473, 571);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(68, 21);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"cos(x)";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(473, 601);
			this->checkBox2->Margin = System::Windows::Forms::Padding(4);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(53, 21);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"s(x)";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(473, 630);
			this->checkBox3->Margin = System::Windows::Forms::Padding(4);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(64, 21);
			this->checkBox3->TabIndex = 6;
			this->checkBox3->Text = L"sin(x)";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(627, 417);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(155, 28);
			this->button3->TabIndex = 7;
			this->button3->Text = L"open picture";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(2, 390);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(363, 420);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(840, 738);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender , System::EventArgs^  e)
	{

		int choise = -1;
		if (checkBox1->Checked == true) { choise = 0; };
		if (checkBox2->Checked == true) { choise = 1; };
		if (checkBox3->Checked == true) { choise = 2; };
		if (choise != -1)
		{
			switch (choise)
			{
			case 0:
			{
				chart1->Series[0]->Points->Clear();
				for (double x = -10; x < 10; x += 0.1)
				{
					chart1->Series[0]->Points->AddXY(x ,cos(x));
				}
				chart1->Series[0]->Name = "Y(x)";
				break;
			}

			case 1:
			{
				chart1->Series[0]->Points->Clear();
				for (double x = -10; x < 10; x += 0.1)
				{
					double rez = 0;
					int k = 10;
					for (int n = 0; n < 100; n++)
					{
						rez += cos(n*x) / fact(n);
					}
					chart1->Series[0]->Points->AddXY(x , rez);

				}
				chart1->Series[0]->Name = "S(x)";
				break;
			}

			case 2:
			{
				chart1->Series[0]->Points->Clear();
				for (double x = -10; x < 10; x += 0.1)
				{
					chart1->Series[0]->Points->AddXY(x , sin(x));
				}
				chart1->Series[0]->Name = "Sin(x)";
				break;
			}
			default:
				break;
			}
		}
		else
		{
			MessageBoxButtons::OK;
			MessageBox::Show("No Graphics chosen!");
		};


	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender , System::EventArgs^  e)
	{
		if (checkBox2->Checked == true | checkBox3->Checked == true)
		{
			checkBox2->Checked = false;
			checkBox3->Checked = false;
		}
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender , System::EventArgs^  e)
	{
		if (checkBox1->Checked == true | checkBox3->Checked == true)
		{
			checkBox1->Checked = false;
			checkBox3->Checked = false;
		}
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender , System::EventArgs^  e)
	{
		if (checkBox2->Checked == true | checkBox1->Checked == true)
		{
			checkBox2->Checked = false;
			checkBox1->Checked = false;
		}
	}

	private: System::Void button2_Click(System::Object^  sender , System::EventArgs^  e)
	{
		int x1 = 0 , y1 = 0;
		Graphics ^canvas = pictureBox1->CreateGraphics();
		SolidBrush ^drawing = gcnew SolidBrush(Color::DarkMagenta);
		SolidBrush ^drawing2 = gcnew SolidBrush(Color::Olive);
		pictureBox1->Image = nullptr;
		canvas->Clear(Color::White);
		pictureBox1->Image = Image::FromFile("C:\\3.png");

		for (x1 = 0; x1 < pictureBox1->Width; x1 += 2)
		{
			Sleep(5);
			pictureBox1->Refresh();
			canvas->FillRectangle(drawing , x1 , sin(x1/4) * 40 + 150 , 20 , 20);
		}
		float num = 0.1;

		for (x1 = 1; x1 < pictureBox1->Width; x1 += 2)
		{
			Sleep(5);
			pictureBox1->Refresh();
			canvas->FillEllipse(drawing2, x1, (int)(250/num), 60, 60);
			num += 0.05;
		}
	}

	private: System::Void button3_Click(System::Object^  sender , System::EventArgs^  e)
	{
		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		openFileDialog1->InitialDirectory = "C:\\2.jpg";
		openFileDialog1->Title = "Choose picture to open";
		openFileDialog1->FileName = "";
		openFileDialog1->ShowDialog();
		pictureBox1->Image = Image::FromFile(openFileDialog1->FileName);
	}
	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
