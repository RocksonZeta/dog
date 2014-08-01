using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace face
{
    class Message
    {
        public Message(int id, String app_name, String win_name, long at)
        {
            this.id = id;
            this.app_name = app_name;
            this.win_name = win_name;
            this.at =at;
        }
        public int id;
        public String win_name;
        public String app_name;
        public long at;
    }
}
