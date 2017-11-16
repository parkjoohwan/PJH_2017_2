using lesson1.Command;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace lesson1.viewModel
{
    class PageViewModel :INotifyPropertyChanged
    {

        public event PropertyChangedEventHandler PropertyChanged;

        public ICommand BtnClicked;
        private String _lab1;
        private String _lab2;
        private String _lab3;


        public String Lab1Text
        {
            get
            {
                return _lab1;
            }
            set
            {
                _lab1 = value;
                RaisePropertyChanged();
            }
        }
        public String Lab2Text
        {
            get
            {
                return _lab2;
            }
            set
            {
                _lab2 = value;
                RaisePropertyChanged();
            }
        }
        public String Lab3Text
        {
            get
            {
                return _lab3;
            }
            set
            {
                _lab3 = value;
                RaisePropertyChanged();
            }
        }

        public PageViewModel()
        {
            Lab1Text = "label!!!!!";
            Lab2Text = "2 text";
            Lab3Text = "3 text!!!!!!!";
            BtnClicked = new BtnCommand();
        }


        protected void RaisePropertyChanged([CallerMemberName] string caller = "")
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(caller));
            }
        }

    }
}
