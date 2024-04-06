import React, { useState, useEffect } from 'react'
import "../first/style.css"

const initialItems = [
  { name: 'груша', price: 4, count: 2 },
  { name: 'апельсин', price: 3, count: 6 },
  { name: 'манго', price: 4, count: 10 },
  { name: 'грейпфрут', price: 3, count: 0 },
  { name: 'ананас', price: 5, count: 20 }
]

export default function List() {
  const [sortedItems, setSortedItems] = useState([...initialItems])
  const [alpha, setAlpha] = useState(false)
  const [priceOrder, setPriceOrder] = useState(false)
  const [countOrder, setCountOrder] = useState(false)
  const [total, setTotal] = useState({ price: 0, count: 0 })

  useEffect(() => {
    let totalPrice = 0
    let totalCount = 0

    sortedItems.forEach(item => {
      totalPrice += item.price
      totalCount += item.count
    })

    setTotal({ price: totalPrice, count: totalCount })
  }, [])

  function sortItems(props, dir = false) {
    const sorted = [...sortedItems].sort((a, b) => {
      let op = a[props] < b[props]
      if (dir) op = a[props] > b[props]
      return op ? -1 : 1
    })
    setSortedItems(sorted)
  }
  return (
    <div>
      <div>
        <div onClick={() => setAlpha(!alpha)}><button>По алфавиту</button>
          {alpha && <div className='sortwind' onClick={() => sortItems('name', true)}>↑</div>}
          {alpha && <div className='sortwind' onClick={() => sortItems('name')}>↓</div>}
        </div>
        <div onClick={() => setPriceOrder(!priceOrder)}><button>По цене</button>
          {priceOrder && <div className='sortwind' onClick={() => sortItems('price')}>↑</div>}
          {priceOrder && <div className='sortwind' onClick={() => sortItems('price', true)}>↓</div>}
        </div>
        <div onClick={() => setCountOrder(!countOrder)}><button>По количеству</button>
          {countOrder && <div className='sortwind' onClick={() => sortItems('count')}>↑</div>}
          {countOrder && <div className='sortwind' onClick={() => sortItems('count', true)}>↓</div>}
        </div>
      </div>
      <Product items={sortedItems} />
      <Summary price={total.price} count={total.count} />
    </div>
  )
}
/* в какой редакции  деструктуризация*/
function Product({ items }) {
  let number = 0;

  return (
    <div>
      <div className='tablestyle'>
        <div>Номер</div>
        <div>Название</div>
        <div>Цена</div>
        <div>Количество</div>
      </div>
      {items.map(item => (
        <div className='tablestyle' key={item.name}>
          <div>{++number}</div>
          <div>{item.name}</div>
          <div>{`${item.price} руб.`}</div>
          <div className={item.count < 1 ? 'red' : item.count < 4 ? 'yellow' : ''}>{item.count}</div>
        </div>
      ))}
    </div>
  )
}

export function Summary({ price, count }) {
  return (
    <div>
      <div>{`Общая стоимость: ${price} руб.`}</div>
      <div>{`Всего товаров: ${count}`}</div>
    </div>
  )
}
