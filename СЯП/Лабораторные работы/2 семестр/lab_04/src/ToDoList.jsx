import React, { useState } from 'react'
import './TaskList.css'

const TaskList = () => {
  const [items, setItems] = useState([])
  const [newItem, setNewItem] = useState('')
  const [view, setView] = useState('all')

  const AddItem = () => {
      setItems([...items, { name: newItem, done: false }])
      setNewItem('')
  }

  const ToggleComplete = (index) => {
    const updatedItems = [...items]
    updatedItems[index].done = !updatedItems[index].done
    setItems(updatedItems)
  }

  let visibleItems
  if (view === 'completed') {
    visibleItems = items.filter(item => item.done)
  } else if (view === 'active') {
    visibleItems = items.filter(item => !item.done)
  } else {
    visibleItems = items
  }

    return (
      <div className="task-list">
        <TaskForm
          newItem={newItem}
          setNewItem={setNewItem}
          AddItem={AddItem}
        />
        <TaskElements
          items={visibleItems}
          ToggleComplete={ToggleComplete}
        />
        <button className="filter-button" onClick={() => setView('all')}>all</button>
        <button className="filter-button" onClick={() => setView('completed')}>completed</button>
        <button className="filter-button" onClick={() => setView('active')}>active</button>
      </div>
    )
}

const TaskForm = ({ newItem, setNewItem, AddItem }) => {
  return (
    <div className="task-form">
      <input
        type="text"
        value={newItem}
        onChange={(e) => setNewItem(e.target.value)}
        className="task-input"
      />
      <button onClick={AddItem} className="add-button">add</button>
    </div>
  )
}

const TaskElements = ({ items, ToggleComplete }) => {
  return (
    <ul className="task-items">
      {items.map((item, index) => (
        <li key={index} className="task-item">
          <input
            type="checkbox"
            checked={item.done}
            onChange={() => ToggleComplete(index)}
            className="task-checkbox"
          />
          <span style={{ textDecoration: item.done ? 'line-through' : 'none' }} className="task-name">{item.name}</span>
        </li>
      ))}
    </ul>
  )
}

export default TaskList
