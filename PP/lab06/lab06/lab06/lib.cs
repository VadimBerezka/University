namespace Lab6Lib
{
    public interface ISubscriber // интерфейс подписчика
    {
        void update( // вызвать при наступлении события
            string eventname // имя события
            );
    }

    public class Publisher
    {
        private string evName;
        private List<ISubscriber> subs = new List<ISubscriber>();

        public Publisher(string eventname) // наименование события 
        {
            evName = eventname;
        }

        public void subscribe(ISubscriber subscriber) // подписаться на событие
        {
            subs.Add(subscriber);
        }

        public bool unsubscribe(ISubscriber subscriber) // отписаться от события 
        {
            return subs.Remove(subscriber);  // отписался?
        }


        public int nonify() // уведомить всех подписчиков о наступлении события 
        {
            foreach (ISubscriber subscriber in subs)
            {
                subscriber.update(evName);
            }
            return subs.Count; // кол-во уведомленных подписчиков
        }
    }
}