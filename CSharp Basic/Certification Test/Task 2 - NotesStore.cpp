Sample Input:
6
AddNote active DrinkTea
AddNote active DrinkCoffee
AddNote completed Study
GetNotes active 
GetNotes completed
GetNotes foo

Sample Output:
DrinkTea,DrinkCoffee
Study
Error: Invalid state foo
















using System;
using System.Collections.Generic;
using System.IO;

namespace Solution
{
    public class Note
    {
        private string name;
        private string state;
          public string Name 
           {
             get { return name; }
            set { name = value; }
           }
        public string State//complete, active, others
        {
            get { return state; }
            set { state = value; }
        }
        
        public Note(string s, string n)
        {
            state=s;
            name=n;
        }
    }

    public class NotesStore
    {
        List<Note> notes;
        public NotesStore() 
        {
            notes = new List<Note>();
        }
        public void AddNote(String state, String name) 
        {
            if(name=="")
            {
                Console.WriteLine($"Error: Name cannot be empty");
            }
            if((state!="active")&&(state!="completed")&&(state!="others"))
            {
                Console.WriteLine($"Error: Invalid state {state}");
            }
            Note n=new Note(state,name);
            notes.Add(n);
        }
        public List<String> GetNotes(String state) 
        {
            List<String> noteNames=new List<string>();
            if((state!="active")&&(state!="completed")&&(state!="others"))
            {
                Console.WriteLine($"Error: Invalid state {state}");
                return noteNames;
            }
            else
            {
            foreach(Note n in notes)
            {
                if(n.State==state)
                {
                    noteNames.Add(n.Name);
                }
            }
            return noteNames;
            }
        }
    } 

    public class Solution
    {
        public static void Main() 
        {
            var notesStoreObj = new NotesStore();
            var n = int.Parse(Console.ReadLine());
            for (var i = 0; i < n; i++) {
                var operationInfo = Console.ReadLine().Split(' ');
                try
                {
                    if (operationInfo[0] == "AddNote")
                        notesStoreObj.AddNote(operationInfo[1], operationInfo.Length == 2 ? "" : operationInfo[2]);
                    else if (operationInfo[0] == "GetNotes")
                    {
                        var result = notesStoreObj.GetNotes(operationInfo[1]);
                        if (result.Count == 0)
                            Console.WriteLine("No Notes");
                        else
                            Console.WriteLine(string.Join(",", result));
                    } else {
                        Console.WriteLine("Invalid Parameter");
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Error: " + e.Message);
                }
            }
        }
    }
}