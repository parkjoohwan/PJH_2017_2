using App1.model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace App1.viewmodel
{
    public class Sample3ViewModel
    {
        public ObservableCollection<Person> People { get; set; }

        public Sample3ViewModel()
        {
            People = new ObservableCollection<Person>();

            for (int i = 0; i < 15; i++)
            {
                Person p = new Person();
                p.Name = "Person" + i;
                p.Address = "Address" + i;
                p.Phone = "Pheon" + i;
                People.Add(p);
            }
        }
    }
}
