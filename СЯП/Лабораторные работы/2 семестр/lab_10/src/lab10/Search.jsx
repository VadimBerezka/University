import React, {useState, useEffect, useRef} from 'react'
import "./Search.css"

export default function Search({list}) {
    const [item, setItem] = useState([])
    const [versions, setVersions] = useState([])
    const [value, setValue] = useState('')
    const [setting, setSetting] = useState ("partial")
    const versionsDisplay = useRef()
    const closebtn = useRef()

    useEffect(() => {
        if (setting === "partial"){
            setVersions(
                list.filter(product => product.name.toLowerCase().includes(value.toLowerCase()))
            )
        }
        if (setting === "exact"){
            setVersions(
                list.filter(product => product.name.toLowerCase() === value.toLowerCase())
            )
        }
    
      }, [value]);

      const itemHandler = (id) => {
       setItem(versions.filter(product => product.id === id))
       closebtn.current.style.display = 'block'
      }

      function close(e){
        setItem([])
        setValue('')
        versionsDisplay.current.style.display = 'none'
        e.target.style.display = 'none'
    }
      
    return(
        <>
         <form>
        <label>Совпадение:</label>
        <select onChange = {(e) => {setSetting(e.target.value)}}>
        <option value = {"partial"} >частичное</option>
        <option value = {"exact"} >точное</option>
        </select>
        </form>
        <div onFocus={() => versionsDisplay.current.style.display = 'block'}>
        <input type = "text" value = {value} onChange = { (e) => {setValue(e.target.value)}} ></input>
        <div ref = {versionsDisplay} style = {{display: "none"}}>
        {versions.map(product => (
            <p key = {versions.indexOf(product)} onClick = { () => itemHandler(product.id) } >{product.name}</p>
        ))}
        </div>
        </div>
        <button className="closebtn" style = {{display: "none"}} ref = {closebtn} onClick = { (e) => close(e) } >&times;</button> 
        {item.map(item => (
                <div key={item.id} className="item1">
                    <div className="item-header">
                        <div className="image">
                            <img src={item.image} alt={item.name} />
                            <div className="discount">{item.discount}%</div>
                        </div>
                        <div className="info">
                            <div className="name" >{item.name}</div>
                            <div className="prices">
                                <span className="old-price" >{item.cost}$</span>
                                <span className="new-price">{item.cost - (item.cost * (item.discount / 100))}$</span>
                            </div>
                            <div className="description">{item.description}</div>
                        </div>
                    </div>
                    <div className="item-footer">
                        <div className="quantity" >Количество: {item.quantity}</div>
                    </div>
                </div>
            ))}
        </>
    )
}
  