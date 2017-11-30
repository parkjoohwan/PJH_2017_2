using App1.view;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Xamarin.Forms;

namespace App1.viewmodel
{
    public class Sample4ViewModel : INotifyPropertyChanged
    {
        // 멤버변수와 getter setter를 약식으로 만든 것 아래의 주석의 내용임
        //public string text { get; set; }

        private String _text;
        public String Text
        {
            get
            {
                return _text;
            }
            set
            {
                _text = value;
                //텍스트(데이터)가 변화되면 이를 알려줌
                RaisePropertyChanged("Text");
            }
        }

        public ICommand SetTextCommand { get; set; }

        public Sample4ViewModel()
        {
            Text = "";
            SetTextCommand = new Command(SetText);
        }

        private void SetText(object obj)
        {
            Text = "Text Notified!!";
        }

        // 함수를 입력 받을 수 있는 변수 데이터가 바뀌었을때 호출하면 뷰가 데이터가 바뀐것을 알게됨
        public event PropertyChangedEventHandler PropertyChanged;

        private void RaisePropertyChanged(String pname)
        {
            //함수가 들어와있다면
            if( PropertyChanged != null )
            {
                //property의 이름이 바뀌었다는 걸 이 함수 호출을 통해 알려줌
                PropertyChanged(this, new PropertyChangedEventArgs(pname));
            }
        }
    }
}
