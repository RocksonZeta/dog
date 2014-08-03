using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Data;


/**
 * select m.id,m.app_name,m.win_name,(m.at-pre.at)/1000 as t from messages m left join (select id+1 as id ,at  from messages) pre on m.id=pre.id
 * 
 */
namespace face
{
    class Messages
    {
        SQLiteConnection con ;
        SQLiteCommand cmd;
        SQLiteDataAdapter db;
        DataSet ds = new DataSet();
        DataTable dt = new DataTable();

        string db_path = System.Environment.GetEnvironmentVariable("APPDATA") + "\\ququ\\dog.sqlite";


        public static Messages instance = new Messages();

        private Messages()
        {
            try
            {

                con = new SQLiteConnection("Data Source=" + db_path + ";Version=3;New=False;Compress=True;");
            con.Open();
            cmd = con.CreateCommand();
            }
            catch (Exception e)
            {
                
            }

        }
        private void SetConnection()
        {
            con = new SQLiteConnection
                ("Data Source=" + db_path + ";Version=3;New=False;Compress=True;");
        } 
        private void ExecuteQuery(string txtQuery)
        {

            cmd = con.CreateCommand();
            cmd.CommandText = txtQuery;
            cmd.ExecuteNonQuery();
        }

        public void LoadData(System.Windows.Forms.DataGridView tb)
        {
            cmd = con.CreateCommand();
            string CommandText = "select id, app_name ,win_name,`at` from messages";
            db = new SQLiteDataAdapter(CommandText, con);
            ds.Reset();
            db.Fill(ds);
            dt = ds.Tables[0];
            tb.DataSource = dt;
        }

        
        public List<Message> get(){
            cmd.CommandText = "select id,app_name,win_name,`at` from messages";
            SQLiteDataReader reader = cmd.ExecuteReader();
            List<Message> r = new List<Message>();
            while (reader.Read())
            {
                r.Add(new Message(reader.GetInt32(0) , reader.GetString(1),reader.GetString(2),reader.GetInt64(3)));
            }
            return r;
        }
        /*
        private void Add()
        {
            string txtSQLQuery = "insert into  messages (desc) values ('" + txtDesc.Text + "')";
            ExecuteQuery(txtSQLQuery);
        }
         */
    }
}
