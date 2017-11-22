using lesson1.viewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;


namespace lesson1
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class Page1 : ContentPage
    {
        private int i = 0;
        public Page1()
        {
            InitializeComponent();

            this.BindingContext = new PageViewModel();
        }

        private void Button_Clicked(object sender, EventArgs e)
        {
            this.lab1.Text = i + "Clicked!!";
            i++;
        }
    }
}