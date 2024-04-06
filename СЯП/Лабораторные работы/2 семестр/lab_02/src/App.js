import './App.css'
import Clock from './first/Clock'
import JobMenu from './first/Job'
function App() {
  return (
    <div>
      <Clock timezone="+3"/>
      <br />
      <JobMenu />
      <br />
    </div>
  )
}

export default App
