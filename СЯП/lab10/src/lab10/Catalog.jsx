import React, {useState, useEffect} from 'react'
import {list_of_products} from './products.js'
import Search from './Search.jsx'
import "./Catalog.css"

export default function Catalog() {
    const [list, setList] = useState(list_of_products)
    const [property, setProperty] = useState('name')
    useEffect(() => {
        if (property === 'discount'){
            let newList1 = list.filter(product => product.isNew === true)
            let newList2 = list.filter(product => product.isNew === false)
            newList1 = newList1.sort((product1, product2) => {return product1[property] < product2[property] ? 1 : -1})
            newList2 = newList2.sort((product1, product2) => {return product1[property] < product2[property] ? 1 : -1})
            const copy = newList1.concat(newList2)
            setList(copy)
        }
        else {
            let newList1 = list.filter(product => product.isNew === true)
            let newList2 = list.filter(product => product.isNew === false)
            newList1 = newList1.sort((product1, product2) => {return product1[property] > product2[property] ? 1 : -1})
            newList2 = newList2.sort((product1, product2) => {return product1[property] > product2[property] ? 1 : -1})
            const copy = newList1.concat(newList2)
            setList(copy)
        }
      }, [property, list]);
    return(
        <>
        <Search list = {list}/>
        <form>
        <label>Сортировать по:</label>
        <select onChange = {(e) => {setProperty(e.target.value)}}>
        <option value="name" >наименованию</option>
        <option value="cost" >цена min</option>
        <option value="quantity" >количеству</option>
        <option value="discount" >скидке</option>
        </select>
        </form>
            {list.map(item => (
                <div key={item.id} className="item1">
                    <div className="item-header">
                        <div className="image">
                            <img src={item.image} alt={item.name} />
                            <div className="discount">{item.discount}%</div>
                        </div>
                        <div className="info">
                            <div className="name" >{item.name}</div>
                            <div className="prices">
                                <span className="old-price" >{item.cost}</span>
                                <span className="new-price">{item.cost - (item.cost * (item.discount / 100))}</span>
                            </div>
                            <div className="description">{item.description}</div>
                        </div>
                    </div>
                    <div className="item-footer">
                        <div className="quantity" >Количество: {item.quantity}</div>
                        <div className="isNew">{item.isNew ? 'Новинка' : ''}</div>
                        <div>Масса:{item.mass}</div>
                    </div>
                </div>
            ))}
        </>
    )
}
