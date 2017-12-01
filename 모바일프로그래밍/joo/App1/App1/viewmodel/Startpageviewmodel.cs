using App1.view;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Xamarin.Forms;

namespace App1.viewmodel
{
    public class Startpageviewmodel
    {

        public string Title { get; set; }
        public ICommand Clicked { get; set; }

        public INavigation Navigation { get; set; }
        

        public Startpageviewmodel(StartPage startPage)
        {
            Title = "StartPage!!!";
            Clicked = new Command(Sample_clicked);
            Navigation = startPage.Navigation;
        }

        // 문자열이 넘어왔을 때 해당 문자열에 해당하는 페이지로
        // 네비게이션해주는 역할을 하는 함수
        private void Sample_clicked(object obj)
        {
            switch (obj)
            {
                case "sample1":
                    Navigation.PushAsync(new Sample1());
                    break;
                case "sample2":
                    Navigation.PushAsync(new Sample2());
                    break;
                case "sample3":
                    Navigation.PushAsync(new Sample3());
                    break;
                case "sample4":
                    Navigation.PushAsync(new Sample4());
                    break;
                default:
                    break;
            }
             //string name = obj as string;

            //if (name == "sample1")
            //{
            //    Navigation.PushAsync(new Sample1());
            //}
            //else if (name == "sample2")
            //{
            //    Navigation.PushAsync(new Sample2());
            //}
            //else
            //{

            //}


        }
    }
}
