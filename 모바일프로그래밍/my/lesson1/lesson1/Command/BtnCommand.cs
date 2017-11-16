using lesson1.viewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace lesson1.Command
{
    public class BtnCommand : ICommand

    {
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            return true;
        }
        int i = 0;

        public void Execute(object parameter)
        {
            //무언가를 한다.
            Page1 p = parameter as Page1;
            PageViewModel vm = p.BindingContext as PageViewModel;
            
            vm.Lab1Text = i +"Clicked";
            i++;
        }
    }
}
