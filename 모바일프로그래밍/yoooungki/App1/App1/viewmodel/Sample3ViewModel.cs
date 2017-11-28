using App1.model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Xamarin.Forms;

namespace App1.viewmodel
{
    public class Sample3ViewModel

    {
        public ICommand ItemSelectedCommand { get; set; }
        public ObservableCollection<Person> People { get; set; }

        public Sample3ViewModel()
        {
            People = new ObservableCollection<Person>();
            ItemSelectedCommand = new Command(ItemSelected);
            for (int i = 0; i < 15; i++)
            {
                Person p = new Person();
                p.Name = "Person" + i;
                p.Address = "Address" + i;
                p.Phone = "Pheon" + i;
                p.Image = "image" + (i % 5) + ".png";
                People.Add(p);
            }
        }

        private void ItemSelected(object obj)
        {
            var page = obj as ContentPage;
            page.DisplayAlert("ItemSelected Event", "이벤트가 선택되었습니다.", "ok");
        }
    }
}
