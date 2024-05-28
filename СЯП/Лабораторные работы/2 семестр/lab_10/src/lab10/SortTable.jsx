import React, { useState } from 'react'
import { list_of_products } from './products.js'
import "./SortTable.css"

export default function SortTables() {
    const [list, setList] = useState(list_of_products)
    const [sort, setSort] = useState(true)
    function SortProducts(property) {
        const copy = list.concat()
        if (sort) {
            const newList = copy.sort((product1, product2) => { return product1[property] < product2[property] ? 1 : -1 })
            setSort(false)
            setList(newList)
        }
        else {
            const newList = copy.sort((product1, product2) => { return product1[property] > product2[property] ? 1 : -1 })
            setSort(true)
            setList(newList)
        }
    }
    return (
        <>
            <table>
                <thead>
                    <tr>
                        <td onClick={() => { SortProducts('name') }} >Наименование</td>
                        <td onClick={() => { SortProducts('cost') }} >Стоимость</td>
                        <td onClick={() => { SortProducts('quantity') }} >Количество</td>
                        <td>Изображение</td>
                        <td>Описание</td>
                        <td>Новинка</td>
                        <td onClick={() => { SortProducts('discount') }} >Скидка</td>
                    </tr>
                </thead>
                <tbody>
                    {
                        list.map((product) => (
                            (
                                <tr key={product.id}>
                                    <td>{product.name}</td>
                                    <td>{product.cost}$</td>
                                    <td>{product.quantity}</td>
                                    <td>
                                        <img src={product.image} />
                                    </td>
                                    <td>{product.description}</td>
                                    <td>{(product.isNew) ? 'новинка' : ""}</td>
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



/* function SortProducts(property) {...}: Объявляем функцию SortProducts, которая будет отвечать за сортировку таблицы по выбранному свойству.
const copy = list.concat(): Создаем копию списка продуктов, чтобы не изменять оригинальный список.
if (sort) {...} else {...}: Проверяем, в каком направлении нужно выполнить сортировку (по возрастанию или убыванию).
const newList = copy.sort((product1, product2) => {...}): Сортируем копию списка продуктов по выбранному свойству (name, cost, quantity или discount) в зависимости от значения sort.
setSort(false) или setSort(true): Меняем значение состояния sort на противоположное.
setList(newList): Обновляем состояние list с отсортированным списком продуктов. */