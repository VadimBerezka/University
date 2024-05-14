import React, {useRef} from "react";
import { useSelector, useDispatch } from 'react-redux'
import { useNavigate } from 'react-router-dom';

import {
    setAddress,
    setDelivery,
    setPayment,
    setOrders,
  } from './OrderSlice';

  import {
    removeOrder, 
  } from './BusketSlice';

import './Order.css'

export default function Order(){
    const orderList = useSelector ( state => state.busket.orderProducts)
    const address = useSelector (state => state.order.orderInf.address)
    const delivery = useSelector (state => state.order.orderInf.delivery)
    const payment = useSelector (state => state.order.orderInf.payment)
    const navigate = useNavigate()
    const dispatch = useDispatch()
    const deliveryDisabled = useRef()

    function buy(order){
        if (delivery !== '' && payment !== ''){
            if (delivery === 'самовывоз'){
                navigate('end', { replace: false })
                dispatch(setOrders(order))
            }
            else {
                if (address !== ''){
                    navigate('end', { replace: false })
                    dispatch(setOrders(order))
                }
            }
        }
    }

    return(
    <div>
        <div>
        <fieldset>
        <legend>Способ доставки</legend>
        <input type = 'radio' name="delivery" value = 'курьер' onChange = { (e) => {
            deliveryDisabled.current.disabled = false; 
            dispatch(setDelivery(e.target.value))
            }}/>
        <label>курьером (если стоимость заказа меньше 200 рублей, то стоимость 10 рублей, если больше, то бесплатно)</label>
        <input type = 'radio' name="delivery" value = 'почта' onChange = { (e) => {
            deliveryDisabled.current.disabled = false;
            dispatch(setDelivery(e.target.value))}}/>
        <label>почтой (5 рублей за каждый килограмм массы)</label>
        <input type = 'radio' name="delivery" value = 'самовывоз' onChange = { (e) => {
            deliveryDisabled.current.disabled = true;
            dispatch(setDelivery(e.target.value))}}/>
        <label>самовывоз (бесплатно)</label>
        </fieldset>
        </div>
        <div>
        <label>Введите адрес</label>
        <input ref = {deliveryDisabled} type = 'text' value = {address} onChange = { (e) => dispatch(setAddress(e.target.value))} disabled = {true}></input>
        </div>
        <div>
        <fieldset>
        <legend>Способ оплаты</legend>
        <input type = 'radio' name = 'payment' value = 'наличные' onChange = { (e) => dispatch(setPayment(e.target.value))}/>
        <label>наличными</label>
        <input type = 'radio' name = 'payment' value = 'карта' onChange = { (e) => dispatch(setPayment(e.target.value))}/>
        <label>картой</label>
        <input type = 'radio' name = 'payment' value = 'перевод' onChange = { (e) => dispatch(setPayment(e.target.value))}/>
        <label>переводом</label>
        </fieldset>
        </div>
        {orderList.map(item => (
                <div key={item.id} className="item10">
                    <div className="item-header">
                        <div className="image10">
                            <img src={item.image} alt={item.name} />
                        </div>
                        <div className="info">
                            <div className="name" >{item.name}</div>
                            <div className="prices">
                                <span className="old-price" >{item.cost}</span>
                                <span className="new-price">{item.cost - (item.cost * (item.discount / 100))}</span>
                            </div>
                        </div>
                    </div>
                    <div className="item-footer">
                        <div className="quantity" >Количество: {item.count_in_order}</div>
                        <div className="isNew">{item.isNew ? 'Новинка' : ''}</div>
                        <div>Масса:{item.mass}</div>
                    </div>
                    <button className="closebtn" onClick = { () => dispatch(removeOrder(orderList.indexOf(item))) } >&times;</button> 
                </div>
                
            ))}
             <button onClick={() => navigate('/', { replace: false })}>Вернуться в корзину</button>
        <button onClick = { () => {buy(orderList)} }>Оформитть заказ</button>
    </div>
    )
}