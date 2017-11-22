using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson1.viewModel
{
    class PageViewModel
    {
        private String _lab1;
        //public int Lab1 { get; set; } // 접근자, 설정자를 한줄로
        // property란 변수에 접근자, 설정자를 합쳐놓은 개념
        public String lab1
        {
            get
            {
                return _lab1;
            }
            set
            {
                _lab1 = value;
            }
        }

        public String Lab1Text{ get; set; }
        public String Lab2Text { get; set; }
        public String Lab3Text { get; set; }

        public PageViewModel()
        {
            Lab1Text = "1번 텍스트";
            Lab2Text = "2번 텍스트";
            Lab3Text = "3번 텍스트";

        }

    }
}
