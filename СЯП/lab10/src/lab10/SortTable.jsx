import React, {useState} from 'react'
import {list_of_products} from './products.js'
import "./SortTable.css"

export default function SortTables() {
    const [list, setList] = useState(list_of_products)
    const [sort, setSort] = useState(true)
    function SortProducts ( property ){
        const copy = list.concat()
        if (sort){
            const newList = copy.sort((product1, product2) => {return product1[property] < product2[property] ? 1 : -1})
            setSort(false)
            setList(newList)
        }
        else {
            const newList = copy.sort((product1, product2) => {return product1[property] > product2[property] ? 1 : -1})
            setSort(true)
            setList(newList)
        }
    }
    return(
        <>
        <table>
            <thead>
            <tr>
                <td onClick={() => {SortProducts('name')}} >наименование</td>
                <td onClick={() => {SortProducts('cost')}} >стоимость</td>
                <td onClick={() => {SortProducts('quantity')}} >количество</td>
                <td>изображение</td>
                <td>описание</td>
                <td>новинка</td>
                <td onClick={() => {SortProducts('discount')}} >скидка</td>
            </tr>
            </thead>
            <tbody>
         
            {
                list.map((product)=> (
                    (
                        <tr key={product.id}> 
                            <td>{product.name}</td>
                            <td>{product.cost}</td>
                            <td>{product.quantity}</td>
                            <td>
                                <img src={product.image}/>
                            </td>
                            <td>{product.description}</td>
                            <td>{(product.isNew)?'новинка': ""}</td>
                            <td>{product.discount}%</td>
                        </tr>
                    )
                ))
            }
         </tbody>
        </table>
        </>
    )
}