import React, {useEffect} from 'react' 
import { useNavigate } from 'react-router-dom';
import { useSelector, useDispatch } from 'react-redux'
import {
    decrement,
    increment,
    remove, 
    addToOrder,
    changeOrder
  } from './BusketSlice';
import "./Catalog.css"

export default function Busket() {
    const list = useSelector ( state => state.busket.busket)
    const dispatch = useDispatch()
    const navigate = useNavigate()

    return(
        <>
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
                    <span>
                    <p>Добавить в заказ</p>
                    <input type = 'checkbox' checked = {item.checked} onChange={ () => dispatch(addToOrder(list.indexOf(item)))}/>
                    <p>Количество в корзине</p>
                    <button onClick={() => dispatch(decrement(list.indexOf(item)))}>-</button>
                    <p>{item.count_in_order}</p>
                    <button onClick={() => dispatch(increment(list.indexOf(item)))}>+</button>
                    <button onClick = {() => dispatch(remove(list.indexOf(item)))}>удалить</button>
                    </span>
                </div>
                
            ))}
            <button onClick={() => navigate('order', { replace: false })}>оформить заказ</button>
        </>
    )
}
