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
            Clicked = new Command(Sample1_clicked);
            Navigation = startPage.Navigation;
        }

        private void Sample1_clicked(object obj)
        {
            Navigation.PushAsync(new Sample1());
        }
    }
}
